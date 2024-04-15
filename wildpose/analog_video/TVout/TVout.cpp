/*
 Copyright (c) 2010 Myles Metzer

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
*/

/*
 This library provides a simple method for outputting data to a tv
 from a frame buffer stored in sram.  This implementation is done
 completly by interupt and will return give as much cpu time to the
 application as possible.
 
 Limitations:
  -	Currently only works with NTSC. PAl support would require modifying
	the timings in video_gen.h as well as the OCR1A ISR to allow for a 16bit
	line counter.
  -	each frame only consists of 256 scanlines vs 262 for the fake progressive
	signal this is supposed to generate (works fine on my tv).
  - virtical sync does not match the specs at all.
 

 current hardware setup:
 Pin9: Sync line:  -->|--/\/\/\--o
                   Diode 1Kohm   |
 Pin8: Video line: -->|--/\/\/\--o---------------- RCA tip
                   Diode 330ohm  |
                                 o--/--/\/\/\--o-- RCA GND
							     Switch  75ohm  |
									            V
											   GND
											   
 
*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "TVout.h"
#include "video_gen.h"

PROGMEM const unsigned char ascii[] = { 
#include "font_set.h"
};

/* call this to start video output
*/
void TVout::start_render() {

	scanLine = 0;
	clear_screen();
	
	//setup the ports
	DDRB |= 0x03;
	PORTB &= ~0x02;
	PORTB |= 0x02;

	// inverted fast pwm mode on timer 1
	TCCR1A = _BV(COM1A1) | _BV(COM1A0) | _BV(WGM11);
	TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10);
	ICR1 = CYCLES_SCANLINE;
	OCR1A = CYCLES_HORZ_SYNC;
	OCR1B = CYCLES_OUTPUT_START-20;

	TIMSK1 = _BV(OCIE1A);
	
	sei();
}

/* Clears the screen
*/
void TVout::clear_screen() {
	for (int i = 0; i < (RESOLUTION_HORIZONTAL/8)*RESOLUTION_VERTICAL; i++)
		screen[i] = 0;
}

/* plot one point 
 * at x,y with color 1=white 0=black 2=invert
 */
void TVout::set_pixel(char x, char y, char c) {
	//each line has 18 bytes
	//calculate i based upon this and x,y
	// the byte with the pixel in it
	char pos[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i = (x/8) + ((int)y*16);

	if (c==1)
	  screen[i] = screen[i] | pos[x & 7];
    else if (c==0)
	  screen[i] = screen[i] & ~pos[x & 7];
    else
	  screen[i] = screen[i] ^ pos[x & 7];
}

/* draw a line
 * x1,y1 to x2,y2
 * with color 1 = white, 0=black, 2=invert
 */
void TVout::draw_line(char x1, char y1, char x2, char y2, char c) {
	int e;
	signed int dx,dy,j, temp;
	signed char s1,s2, xchange;
    signed int x,y;
        
	x = x1;
	y = y1;
	
	//take absolute value
	if (x2 < x1) {
		dx = x1 - x2;
		s1 = -1;
	}
	else if (x2 == x1) {
		dx = 0;
		s1 = 0;
	}
	else {
		dx = x2 - x1;
		s1 = 1;
	}

	if (y2 < y1) {
		dy = y1 - y2;
		s2 = -1;
	}
	else if (y2 == y1) {
		dy = 0;
		s2 = 0;
	}
	else {
		dy = y2 - y1;
		s2 = 1;
	}

	xchange = 0;   

	if (dy>dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		xchange = 1;
	} 

	e = ((int)dy<<1) - dx;  
	 
	for (j=0; j<=dx; j++) {
		set_pixel(x,y,c);
		 
		if (e>=0) {
			if (xchange==1) x = x + s1;
			else y = y + s2;
			e = e - ((int)dx<<1);
		}
		if (xchange==1)
			y = y + s2;
		else
			x = x + s1;
		e = e + ((int)dy<<1);
	}
}

/* print a character c at x,y
*/
void TVout::print_char(char x, char y, char c) { 
    char i;
	char y_pos;
	uint8_t j;

	for (i=0;i<7;i++) {
        y_pos = y + i;

		j = pgm_read_byte(((uint32_t)(ascii)) + c*7 + i);

        set_pixel(x,   y_pos, (j & 0x80)==0x80);  
        set_pixel(x+1, y_pos, (j & 0x40)==0x40); 
        set_pixel(x+2, y_pos, (j & 0x20)==0x20);
        set_pixel(x+3, y_pos, (j & 0x10)==0x10);
        set_pixel(x+4, y_pos, (j & 0x08)==0x08);
    }
}

/* print a null terminated string at x,y
*/
void TVout::print_str(char x, char y, char *str) {
	char i;
	for (i=0; str[i]!=0; i++) { 
		print_char(x,y,str[i]);
		x = x+6;	
	}
}