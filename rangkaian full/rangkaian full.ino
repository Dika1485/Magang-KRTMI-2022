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
  delay(20);
  tombol();
  if(go){
    if(up) {         //will be TRUE as long as button is pressed
      else if (pos - 3 >= 0) pos -= 3 ;
      if(circle)
       else if(pos - 3 >= 0) pos -= 3;
       bool start=GamePad.isStartPressed();
       else if(start){
       else if(pernahstart){
      start=0;
    }
    else{
      pernahstart=1;
    else if(square)
       else if(pos + 3 <= 180) pos += 3;
    }
    else if(down){
      else if (pos + 3 >= 90) pos += 3 ;
      if(circle)
        else if(pos - 3 >= 0) pos -= 3;
      bool start=GamePad.isStartPressed();
       else if(start){
       else if(pernahstart){
      start=0;
    }
    else{
      pernahstart=1;
      else if(square)
        else if(pos + 3 <= 180) pos += 3;
      }
    
    }
    else{
      mandeg();
    }
  }
}
