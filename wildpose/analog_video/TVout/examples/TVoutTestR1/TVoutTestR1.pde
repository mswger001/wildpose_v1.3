#include <TVout.h>

TVout TV;
char x,y;

void setup()  {
  x=0;
  y=0;
  TV.start_render();
}

void loop() {
  delay(2000);
  TV.clear_screen();
  x=0;
  y=0;
  for (char i = 32; i < 127; i++) {
    TV.print_char(x*6,y*8,i);
    x++;
    if (x >20) {
      y++;
      x=0;
    }
  }
  delay(2000);
  TV.clear_screen();
  TV.print_str(0,0,"fill screen pixel");
  TV.print_str(0,8,"by pixel");
  delay(2000);
  TV.clear_screen();
  for(x=0;x<127;x++){
    for(y=0;y<95;y++){
      TV.set_pixel(x,y,1);
    }
  }
  delay(2000);
  TV.clear_screen();
  TV.print_str(0,0,"draw some lines");
  delay(2000);
  for(y=0;y<95;y++){
    delay(10);
    TV.draw_line(0,y,x-y,y,1);
  }
}

