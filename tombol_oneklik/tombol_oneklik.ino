#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
bool pernahstart=0;
void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);
}

void loop() {
  Dabble.processInput();         
  Serial.print("KeyPressed: ");
  bool start=GamePad.isStartPressed();
  if(start){
    if(pernahstart){
      start=0;
    }
    else{
      pernahstart=1;
    }
  }
  else{
    pernahstart=0;
  }
  if(start) Serial.println("Start");
}