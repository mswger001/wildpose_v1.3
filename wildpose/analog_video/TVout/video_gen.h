#ifndef VIDEO_GEN_H
#define VIDEO_GEN_H

#define CYCLES_PER_US			(F_CPU / 1000000)

//screen properties
#define RESOLUTION_HORIZONTAL 	128 	// must be a multiple of 8
#define RESOLUTION_VERTICAL 	96 		// should be no larger than 100
#define RESOLUTION_VSCALE 		2		// if vres <= 100 set to 2 for squarer pixels

// timing for the video generation
// change these vales for PAL support
// PAL SUPPORT NOT YET WORKING DUE TO LACK OF SCANLINES
#define TIME_SCANLINE			63.625
#define TIME_HORZ_SYNC			4.7
#define TIME_OUTPUT_START		12
#define TIME_VIRT_SYNC			(TIME_SCANLINE - TIME_HORZ_SYNC)

#define LINE_FRAME				262
#define LINE_START_RENDER		35
#define LINE_STOP_RENDER		((LINE_START_RENDER + (RESOLUTION_VERTICAL * RESOLUTION_VSCALE)) - 1)

#define CYCLES_SCANLINE			((TIME_SCANLINE * CYCLES_PER_US) - 1)
#define CYCLES_HORZ_SYNC		((TIME_HORZ_SYNC * CYCLES_PER_US) - 1)
#define CYCLES_OUTPUT_START		((TIME_OUTPUT_START * CYCLES_PER_US) - 1)
#define CYCLES_VIRT_SYNC		((TIME_VIRT_SYNC * CYCLES_PER_US) - 1)

//global variables for the screen
extern volatile unsigned char scanLine;
extern unsigned char screen[(RESOLUTION_HORIZONTAL/8)*RESOLUTION_VERTICAL];

static inline void render_line();
static inline void wait_until(unsigned char time);

#endif