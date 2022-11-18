#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

int pinservo[5] = {1,2,3,4,5};//tanya elektronik di pin apa aja
int pos[5] = {90,90,90,90,90};//koordinasi dengan mekanik sudutnya berapa, pos[0] untuk servo capit
bool up=0,down=0,left=0,right=0;//teruskan deklarasi variable yang ada di prosedur tombol dan pauseorstart dengan nilai 0
Servo servo[5];

void setup(){
  Serial.begin(9600);
  Dabble.begin(9600);
  atursudutservo();
}

void atursudutservo(){
  for(int i=0;i<5;i++){
    servo[i].attach(pos[i]);
  }
}

void tombol(){
  Dabble.processInput();
  Serial.print("KeyPressed: ");
  up=GamePad.isUpPressed();
  down=GamePad.isDownPressed();
  left=GamePad.isLeftPressed();
  right=GamePad.isRightPressed();
  squar=GamePad.isSquarePressed();
  circle=GamePad.isCirclePressed();
  cross=GamePad.isCrossPressed();
  triangle=GamePad.isTrianglePressed();
  start=GamePad.isStartPressed();
  select=GamePad.isSelectPressed();
  
  if (start) {
    if (pernahstart) {
      start = 0;
    }
    else {
      pernahstart = 1;
    }
  }
  else {
    pernahstart = 0;
  }
  
  if (squar) {
    if (pernahsquar) {
      squar = 0;
    }
    else {
      pernahsquar = 1;
    }
  }
  else {
    pernahsquar = 0;
  }
  
  if(up){
    Serial.print("UP ");
  }
  if(down){
    Serial.print("DOWN ");
  }
  if(left){
    Serial.print("Left ");
  }
  if(right){
    Serial.print("Right ");
  }
  if(square){
    Serial.print("Square ");
  }
  if(circle){
    Serial.print("Circle ");
  }
  if(cross){
    Serial.print("Cross ");
  }
  if(triangle){
    Serial.print("Triangle ");
  }
  if(start){
    Serial.print("Start ");
  }
  if(select){
    Serial.print("Select ");
  }
  Serial.print('\t');

}

void pauseorstart(){
  if (start){
    if (go) {
      go = 0;
    }
    else {
      go = 1;
    }
  }
}

void capitorno(){
  if(squar){
    if(capit){
      capit=0;
      pos[0]=;//isikan sudut membuka capit
    }
    else{
      capit=1;
      pos[0]=;//isikan sudut mencapit
    }
  }
}
void loop(){
  delay(20);
  tombol();
  pauseorstart();
  if(go){
  if(squar){
      if (start) {
        if (capit) {
           Servo = 0;
           capit = 0;
          } 
         else {
          Servo = 90;
          capit = 1;
         }
  } 
      //lakukan servo one click
    }
    if(circle){
        if(GamePad.isUpPressed()){
         Serial.print("UP ");
         if(pos + 3 <= 90) pos += 3;
         }
        if(GamePad.isDownPressed()){
         Serial.print("DOWN ");
         if(pos - 3 >= 0) pos -= 3;
         }//lakukan servo_1
    }
    if(triangle){
        if(GamePad.isUpPressed()){
         Serial.print("UP ");
         if(pos + 3 <= 90) pos += 3;
         }
        if(GamePad.isDownPressed()){
         Serial.print("DOWN ");
         if(pos - 3 >= 0) pos -= 3;
         } //lakukan servo_1
    }
    if(cross){
        if(GamePad.isLeftPressed()){
            Serial.print("LEFT");
        if(pos + 3 <= 180) pos += 3;
        }
        if(GamePad.isRightPressed()){
           Serial.print("RIGHT");
           if(pos - 3 >= 0) pos -= 3;
            }
        }//lakukan servo_1
    }
  }
  atursudutservo();
}
