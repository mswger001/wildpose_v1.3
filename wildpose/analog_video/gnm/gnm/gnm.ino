#include <TVout.h>
#include <fontALL.h>

TVout TV;
TVout TVLight;
TVout TVDark;
TVout TNnormal;
int incrementPosition = 0; // Variable to track the position of the increment
int totalPoints = 0;
int meanPoints = 0;
char receivedData[10]; // Buffer to store received data from ROS node
int brightnessLevel = 0;

const int TARGET_POINTS = 120 * 96; // Total number of points to cover the entire screen

void setup() {
  Serial.begin(9600);
  TV.begin(NTSC, 120, 96);
  TV.select_font(font6x8);
  setNormalPoints(0);
}


void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == 'r'){
      Serial.println(incrementPosition);
    }
    if (input == 'k'){
      setNormalPoints(4000);
    }
    else if (input == 'l'){
      setNormalPoints(0);
    }
     else if (input == 'n'){
      setNormalPoints(3000);
    }
    else if (input == 'g'){
      setNormalPoints(6000);
      incrementPosition +=1;
      setNormalPoints(3000);
      Serial.print("Position:");
      Serial.println(incrementPosition); // Send position data back to Python node
    }
    else if (input == 'f'){
      setNormalPoints(0);
      incrementPosition -=1;
      if(incrementPosition<0){
        incrementPosition=0;
      }
      setNormalPoints(3000);
      Serial.print("Position:");
      Serial.println(incrementPosition); // Send position data back to Python node
    }

    }
  
}

void setNormalPoints(int targetPoints){
  if (totalPoints< targetPoints){
    increasePoints4(targetPoints);
  }
  else if (totalPoints> targetPoints){
    decreasePoints4(targetPoints);
  }

}


void increasePoints4(int targetPoints) {
  int rowsToAdd = (targetPoints - totalPoints) / TV.hres(); // Calculate number of rows to add
  for (int i = 0; i < rowsToAdd; i++) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, totalPoints / TV.hres(), WHITE); // Set entire row to white
    }
    totalPoints += TV.hres(); // Increment total points by the number of points in a row
  }
}

void decreasePoints4(int targetPoints) {
  int rowsToRemove = (totalPoints - targetPoints) / TV.hres(); // Calculate number of rows to remove
  for (int i = 0; i < rowsToRemove; i++) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, totalPoints / TV.hres() - 1, BLACK); // Set entire row to black
    }
    totalPoints -= TV.hres(); // Decrement total points by the number of points in a row
  }
  meanPoints = totalPoints;
}
