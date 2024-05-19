#include <Motoron.h>

#define HWSERIAL Serial
#define HWSERIAL1 Serial1

MotoronI2C mc(16);  // Motoron controller
#define WIRE Wire // using I2C 0
#define N_MOTOR 3 // the number of motors
#define ZOOM_PIN 14
#define FOCUS_PIN 16
#define RESET 13
#define TIMEOUT 500


#define N_PULSE_PER_REVOLUTION 24 // 24 counts per revolution of the motor shaft when counting both edges of a single channel
#define GEAR_RATIO 98.78  // 98.78:1 metal spur gearbox

int MotorSpeeds[] = {0, 0, 0};  // -800 ~ +800
unsigned long LastCmdTime = 0;

int prevZoomPosition;
int prevFocusPosition;
int prevAperturePosition;
int aperturePosition;

int PreviousPluseCounters[] = {0, 0, 0};
int PluseCounters[] = {0, 0, 0};
float RevolusionLimits[3][2] = {
  {-2.0, 0.0}, 
  {0.0, 2.2}, 
  {0.0, 1.7}
};

char c;
const byte NumChars = 32; 
char ReceivedChars[NumChars]; 
boolean NewData = false;  
char EndMarker = '\n';
const byte NewString = 32;
char Access[NewString];

void setup_motor_driver() {
  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, LOW);
  delay(10);
  digitalWrite(RESET, HIGH);
  delay(1000);
  
  WIRE.begin(); 
  LastCmdTime = millis();
  mc.reinitialize();
  mc.disableCrc();
  mc.clearResetFlag();
  for (int i = 0; i < N_MOTOR; i++) {
    mc.setMaxAcceleration(i, 140);
    mc.setMaxDeceleration(i, 300);
  }

  serial_flush();
}

unsigned long max2(unsigned long a, unsigned long b) {
  return a >= b ? a : b;
}

void setup() {
  Serial.begin(115200);
  HWSERIAL.begin(115200);
  HWSERIAL1.begin(9600);

  setup_motor_driver();

  prevZoomPosition = analogRead(ZOOM_PIN);
  prevFocusPosition = analogRead(FOCUS_PIN);

  HWSERIAL.printf("Zoom position: %d\n", prevZoomPosition);
  HWSERIAL.printf("Focus position: %d\n", prevFocusPosition);
}

void return_potentiometer_positions() {
  int zoomPosition = analogRead(ZOOM_PIN);
  int focusPosition = analogRead(FOCUS_PIN);

  HWSERIAL.printf("z%d\n", zoomPosition);  
  HWSERIAL.printf("f%d\n", focusPosition);  
}

void loop() {
  start_input();
  motor_ctl(); 

  int zoomPosition = analogRead(ZOOM_PIN);
  int focusPosition = analogRead(FOCUS_PIN);
 
  aperturePosition = getAperturePositionFromTeensy(); 

  if (abs(zoomPosition - prevZoomPosition) > 2) {
    HWSERIAL.printf("z%d\n", zoomPosition);  
    prevZoomPosition = zoomPosition;
  }

  if (abs(focusPosition - prevFocusPosition) > 2) {
    HWSERIAL.printf("f%d\n", focusPosition);  
    prevFocusPosition = focusPosition;
  }
 if ( prevAperturePosition != aperturePosition){
    HWSERIAL.printf("a%d\n", aperturePosition);  
  prevAperturePosition = aperturePosition;
 }

}

void serial_flush() {
  while (HWSERIAL.available())
    HWSERIAL.read();
}

void start_input() {
  static byte ndx = 0;
  char rc;  
  unsigned long stime = millis();

  while (HWSERIAL.available() && NewData == false) {
    rc = HWSERIAL.read();

    if (rc != EndMarker) {
      ReceivedChars[ndx++] = rc;
      if (ndx >= NumChars) {
        ndx = NumChars - 1;
      }
    } else {
      ReceivedChars[ndx] = '\0'; 
      ndx = 0;
      NewData = true;
      LastCmdTime = millis();
    }

    if (millis() - stime > TIMEOUT) {
      serial_flush();
      Serial.println("break");
      break;
    }
  }
}

void set_speed(int motor_id, int speed) {
  static int previous_speed = 0; 
  int min_limit = RevolusionLimits[motor_id][0] * GEAR_RATIO * N_PULSE_PER_REVOLUTION;
  int max_limit = RevolusionLimits[motor_id][1] * GEAR_RATIO * N_PULSE_PER_REVOLUTION;

  if (
    !(min_limit <= PluseCounters[motor_id] && PluseCounters[motor_id] <= max_limit) && (
      (PluseCounters[motor_id] < min_limit && sgn(speed) == -1) || (max_limit < PluseCounters[motor_id] && sgn(speed) == 1)
    )
  ) {
    Serial.printf("Limit: %d\n", PluseCounters[motor_id]);
    speed = 0;
  }

  if (motor_id == 2) {
    if (speed != previous_speed) {
      if (speed < 0) {
        HWSERIAL1.print("g\n");
      } else if (speed > 0) {
        HWSERIAL1.print("f\n");
      }
      previous_speed = speed; 
    }
  }

  mc.setSpeed(motor_id + 1, -speed);
}

void motor_ctl() {
  c = ReceivedChars[0];

  if (c == 't' && NewData) {
    int newSpeed;
    c = ReceivedChars[1];
    int motor_id = c - '0';
    char *p = ReceivedChars + 2; 
    strcpy(Access, p); 
    int input = atoi(Access); 

    if ((-800 <= input) && (input <= 800)) {  
      newSpeed = input; 
      MotorSpeeds[motor_id] = newSpeed;
      NewData = false;
    } else {
      Serial.print("Invalid t: ");
      Serial.println(input);
      NewData = false;
    }
  }
  else if (c == 'r' && NewData) {
    char *p = ReceivedChars;
    strcpy(Access, p);

    setup_motor_driver();

    if (strcmp(Access, "reset") == 0) {
      for (int i = 0; i < N_MOTOR; i++) {
        PluseCounters[i] = 0;
        MotorSpeeds[i] = 0;
      }
      Serial.println("Reset.");
      NewData = false;
    } else {
      Serial.print("Invalid r: ");
      Serial.println(Access);
      NewData = false;
    }
  }
  else {
    NewData = false;
  }

  for (int i = 0; i < N_MOTOR; i++) {
    set_speed(i, MotorSpeeds[i]); 
  }
}





String receivedString = "";

int getAperturePositionFromTeensy() {
  while (HWSERIAL1.available()) {
    char receivedChar = HWSERIAL1.read();
    if (receivedChar == '\n') {
      int value = receivedString.toInt(); // Convert the accumulated string to an integer
      receivedString = ""; // Clear the string for the next set of input
      return value;
    } else {
      receivedString += receivedChar; // Accumulate characters into the string
    }
  }
  return prevAperturePosition; // Return previous value if no complete input is received
}



static inline int8_t sgn(int val) {
  if (val < 0) return -1;
  if (val == 0) return 0;
  return 1;
}
