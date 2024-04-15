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
#ifndef TVOUT_H
#define TVOUT_H

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

/*
 TVout.cpp contains a brief expenation of each function.
*/
class TVout {
	public:
		void start_render();
		void clear_screen();
		void set_pixel(char x, char y, char c);
		void draw_line(char x1, char y1, char x2, char y2, char c);
		void print_char(char x, char y, char c);
		void print_str(char x, char y, char *str);
};

#endif