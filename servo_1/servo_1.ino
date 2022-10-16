#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

int pos = 90;
Servo servo_9;

void setup(){
  Serial.begin(9600);
  Dabble.begin(9600);
  servo_9.attach(9);
}

void loop(){
  Dabble.processInput();
  Serial.print("KeyPressed: ");
  if(GamePad.isLeftPressed()){
    Serial.print("LEFT");
    if(pos + 3 <= 180) pos += 3;
  }
  if(GamePad.isRightPressed()){
    Serial.print("RIGHT");
    if(pos - 3 >= 0) pos -= 3;
  }
  servo_9.write(pos);
  delay(10);
}
