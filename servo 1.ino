/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

int pos = 180;
int pos2 = 180;
int RIGHT = 180;
int LEFT = 0;

Servo servo_9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  servo_9.attach(9);
  
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  
  if (GamePad.isLeftPressed())
  {
    Serial.print("LEFT");
    servo_9.write(180);
    delay(100);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("RIGHT");
    servo_9.write(0);
    delay(100);
  }
}

  