#include <TVout.h>
#include <fontALL.h>

TVout TV;
TVout TVLight;
TVout TVDark;
TVout TNnormal;
int totalPoints = 0;
int meanPoints = 0;
char receivedData[10]; // Buffer to store received data from ROS node
int brightnessLevel = 0;

const int TARGET_POINTS = 120 * 96; // Total number of points to cover the entire screen

void setup() {
  Serial.begin(9600);
  TV.begin(NTSC, 120, 96);
  TV.select_font(font6x8);
}

void loop1() {
  // Increase points to maximum
  increasePoints(TARGET_POINTS);
  delay(1000); // Delay after reaching maximum

  // Decrease points to mean
  decreasePoints(meanPoints);
  delay(1000); // Delay after reaching mean

  // Increase points to maximum again
  increasePoints(TARGET_POINTS);
  delay(1000); // Delay after reaching maximum
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == 'w') {
      setNormalPoints(totalPoints+500);
    } else if (input == 'd') {
      setNormalPoints(totalPoints-500);
    }
    else if (input == 'c'){
      setNormalPoints(totalPoints+100);
    }
    else if (input == 't'){
      setNormalPoints(totalPoints+10);
    }
    else if (input == 'y'){
      setNormalPoints(totalPoints+1);
    }
     else if (input == 'u'){
      setNormalPoints(totalPoints-100);
    }
    else if (input == 'i'){
      setNormalPoints(totalPoints-10);
    }
    else if (input == 'p'){
      setNormalPoints(totalPoints-1);
    }
     else if (input == 'k'){
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
      delay(5); g
      setNormalPoints(3000);
      }
    else if (input == 'f'){
      setNormalPoints(0);
      delay(10);
      setNormalPoints(3000);
      }
    Serial.print("Current points: ");
    Serial.println(totalPoints);

  }
  
}
void loop3() {
  if (Serial.available() > 0) {
 
    int bytesRead = Serial.readBytesUntil('\n', receivedData, sizeof(receivedData) - 1);
    receivedData[bytesRead] = '\0'; // Null-terminate the received data
    brightnessLevel = atoi(receivedData); // Convert received data to integer 
    if(brightnessLevel > -1 && brightnessLevel < 200) {
      setNormalPoints(6000+(brightnessLevel-20));
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
  // if (totalPoints< targetPoints){
  //   increasePoints3(targetPoints);
  // }
  // else if (totalPoints> targetPoints){
  //   decreasePoints3(targetPoints);
  // }

  // if (totalPoints< targetPoints){
  //   increasePoints2(targetPoints);
  // }
  // else if (totalPoints> targetPoints){
  //   decreasePoints2(targetPoints);
  // }
}

void increasePoints2(int targetPoints) {
  int y = totalPoints / TV.hres(); // Start from the current row
  int x = totalPoints % TV.hres(); // Start from the current column
  while (totalPoints < targetPoints) {
    TV.set_pixel(x, y, WHITE); // Set the pixel to white
    totalPoints++; // Increment the total points
    x++; // Move to the next column
    if (x >= TV.hres()) { // If reached end of row
      x = 0; // Reset x to start of next row
      y++; // Move to the next row
    }
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between adding points
  }
}

void decreasePoints2(int targetPoints) {
  int y = totalPoints / TV.hres() - 1; // Start from the previous row
  int x = totalPoints % TV.hres() - 1; // Start from the previous column
  while (totalPoints > targetPoints) {
    if (x < 0) { // If reached start of row
      x = TV.hres() - 1; // Reset x to end of previous row
      y--; // Move to the previous row
    }
    TV.set_pixel(x, y, BLACK); // Set the pixel to black
    totalPoints--; // Decrement the total points
    x--; // Move to the previous column
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between removing points
  }
  meanPoints = totalPoints;
}
void increasePoints(int targetPoints) {
  int y = 0;
  while (totalPoints < targetPoints) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, y, WHITE); // Set the pixel to white
      totalPoints++; // Increment the total points
    }
    y++; // Move to the next row
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between adding points
  }
}

void decreasePoints(int targetPoints) {
  int y = TV.vres() - 1;
  while (totalPoints > targetPoints) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, y, BLACK); // Set the pixel to black
      totalPoints--; // Decrement the total points
    }
    y--; // Move to the previous row
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between removing points
  }
  meanPoints = totalPoints;
}

void increasePoints3(int targetPoints) {
  int rowsToAdd = (targetPoints - totalPoints) / TV.hres(); // Calculate number of rows to add
  for (int i = 0; i < rowsToAdd; i++) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, totalPoints / TV.hres(), WHITE); // Set entire row to white
    }
    totalPoints += TV.hres(); // Increment total points by the number of points in a row
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between adding rows
  }
}

void decreasePoints3(int targetPoints) {
  int rowsToRemove = (totalPoints - targetPoints) / TV.hres(); // Calculate number of rows to remove
  for (int i = 0; i < rowsToRemove; i++) {
    for (int x = 0; x < TV.hres(); x++) {
      TV.set_pixel(x, totalPoints / TV.hres() - 1, BLACK); // Set entire row to black
    }
    totalPoints -= TV.hres(); // Decrement total points by the number of points in a row
    Serial.print("Current points: ");
    Serial.print(totalPoints);
    Serial.print(", Target points: ");
    Serial.println(targetPoints);
    delay(10); // Adjust delay time between removing rows
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
