#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

int pinservo[4] = {2,3,4,5};//pin servo
int pos[4] = {100,180,180,90};//koordinasi dengan mekanik sudutnya berapa, pos[0] untuk servo capit
bool up=0,down=0,left=0,right=0,squar=0,circle=0,cross=0,triangle=0,start=0,select=0,pernahstart=0,pernahtriangle=0,go=0,capit=1;//deklarasi variable yang ada di prosedur tombol dan pauseorstart
Servo servo[4];

void setup(){
  Serial.begin(9600);
  Dabble.begin(9600);
  setpinservo();
  atursudutservo();
}

void setpinservo(){
  for(int i=0;i<4;i++){
    servo[i].attach(pinservo[i]);
  }
}

void atursudutservo(){
  for(int i=0;i<4;i++){
    servo[i].write(pos[i]);
    Serial.print(pos[i]);
    Serial.print(" ");
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
  
  if (triangle) {
    if (pernahtriangle) {
      triangle = 0;
    }
    else {
      pernahtriangle = 1;
    }
  }
  else {
    pernahtriangle = 0;
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
  if(squar){
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
  Serial.print('\n');

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
  if(triangle){
    if(capit){
      capit=0;
      pos[0]=50;//isikan sudut membuka capit
    }
    else{
      capit=1;
      pos[0]=100;//isikan sudut mencapit
    }
  }
}
void loop(){
  delay(20);
  tombol();
  pauseorstart();
  if(go){
    if(triangle){
      capitorno();
      //servo one click capit
    }
    if(circle){
      if(up){
        if(pos[2] + 3 <= 180) pos[2] += 3;
      }
      if(down){
        if(pos[2] - 3 >= 0) pos[2] -= 3; 
      }//servo lengan kanan
    }
    if(squar){
      if(up){
        if(pos[1] - 3 >= 0) pos[1] -= 3;
      }
      if(down){
        if(pos[1] + 3 <= 180) pos[1] += 3;
      }//servo lengan kiri
    }
    if(cross){
      if(left){
        if(pos[3] + 3 <= 180) pos[3] += 3;
      }
      if(right){
        if(pos[3] - 3 >= 0) pos[3] -= 3;
      }
    }//servo bawah
  }
  atursudutservo();
}
