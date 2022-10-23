#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

int Servo = 90
bool pernahstart = 0;
bool capit = 0;

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);
  myservo.attach(5);
  myservo.write(Servo);
}

void loop() {
  Dabble.processInput();
  Serial.print("KeyPressed: ");
  bool start = GamePad.isStartPressed();
  if (start) {
    if (pernahstart) {
      start = 0;
    } else {
      pernahstart = 1;
    }
  } else {
    pernahstart = 0;
  }
  if (start) Serial.println("Start");
  bool Servo;
  if (start) {
    if (capit) {
      Servo = 0;
      capit = 0;
    } else {
      Servo = 90;
      capit = 1;
    }
  } 
  myservo.write(Servo);
}