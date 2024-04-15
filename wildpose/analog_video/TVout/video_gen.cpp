#include <avr/interrupt.h>
#include <avr/io.h>

#include "video_gen.h"

//gobal variables 
volatile unsigned char scanLine;	//current scanline
volatile unsigned int renderLine;	//offset from screen of the current line
unsigned char screen[(RESOLUTION_HORIZONTAL/8)*RESOLUTION_VERTICAL];
unsigned char * screenptr;

// this interupt occurs at OCR1A (end of that lines sync period
ISR(TIMER1_COMPA_vect) {
	switch (scanLine) {
		case 2:							//start vsync
			OCR1A = CYCLES_VIRT_SYNC;
			break;
		case 5:							//stop vsync
			OCR1A = CYCLES_HORZ_SYNC;
			break;
		
		case LINE_START_RENDER:			//start to render each line
			TIMSK1 |= _BV(OCIE1B);
			renderLine = 0;
			break;
		case LINE_STOP_RENDER:			//stop rendering each line
			TIMSK1 &= ~_BV(OCIE1B);
			break;
	}
	scanLine++;
}

// render a line
ISR(TIMER1_COMPB_vect) {
	wait_until(CYCLES_OUTPUT_START);
	render_line();
}

/* At the end of the inline assembly timer1 == time
 * time must be at least 10cycles smaller than than 
 * timer1 at the time the asm starts.
 * only works until timer1 == 256.
 */
static inline void wait_until(unsigned char time) {
	
	__asm__ __volatile__ (
		"sub	%[time], %[tcnt1l]\n\t"
		"subi	%[time], 10\n"
	"100:\n\t"
		"subi	%[time], 3\n\t"
		"brcc	100b\n\t"
		"subi	%[time], 0-3\n\t"
		"breq	101f\n\t"
		"dec	%[time]\n\t"
		"breq	102f\n\t"
		"rjmp	102f\n"
	"101:\n\t"
		"nop\n" 
	"102:\n"
	:
	: [time] "a" (time),
	  [tcnt1l] "a" (TCNT1L)
	);
}

/* render a 128 pixel line.
 * 6 cycles/pixel 5 is possible if port state needs to be preserved
 * fewer than 3 cycles should be possible without saving the status of the
 * port. however the output pin would be restricted to the highest or lowest
 * order pin on the output port and the output port must not be the same one
 * sync outputs on (3c would be destructive).
  */
static inline void render_line() {
	screenptr = screen + ((renderLine/RESOLUTION_VSCALE) & 0xFFF0);

	__asm__ __volatile__ (
		//save PORTB
		"IN		r16,%[port]\n\t"
		"ANDI	r16,0xFD\n\t"
			
	".macro output\n\t"
		"BLD	r16,0\n\t"				//output pin of the port here pinB0
		"OUT	%[port],r16\n"			//and on the last line of asm
	".endm\n"
	
	".macro pixeldelay\n\t"				// delay time for setting pixel width
		"NOP\n\t"						// one can be removed for smaller
		"NOP\n\t"						// pixels dont forget to remove the
		"NOP\n\t"						// nop at the start of byteshift
	".endm\n"

	".macro byteshift\n\t"
		"NOP\n\t"
		"BST	__tmp_reg__,7\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,6\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,5\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,4\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,3\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,2\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,1\n\t"
		"output\n\t"
		"pixeldelay\n\t"
		"BST	__tmp_reg__,0\n\t"
		"output\n"
	".endm\n\t"

		//output thingy
		"LD		__tmp_reg__,X+\n\t"		//1
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//2
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//3
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//4
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//5
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//6
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//7
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//8
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//9
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//10
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//11
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//12
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//13
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//14
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//15
		"byteshift\n\t"
		"LD		__tmp_reg__,X+\n\t"		//16
		"byteshift\n"
	
	"EndLine_%=:\n\t"
		"CBI	%[port],0\n\t"
	// assembly variable IO:
	:
	: [port] "i" (_SFR_IO_ADDR(PORTB)),
	  "x" (screenptr)
	: "r16" // try to remove this clobber later...
	);
	renderLine+=16;
}