#include <NewPing.h>
#include <Servo.h>

Servo servoAvant, servoArriere;
NewPing sonar(2,4,200);
char avant[] = {60,100,100,100,100,60,60,60};
char arriere[] = {60,60,100,60,100,100,60,100};

int distance = 0;
int distMin =20;
int pinMoteurAvant = 6;
int pinMoteurarriere = 8;

void setup() {
  servoAvant.attach(pinMoteurAvant);
  servoArriere.attach(pinMoteurarriere);
  Serial.begin(9600);

}

void loop() {
  
  distance = 0;

   while(distance == 0){
      distance = quelleDistance();
      Serial.print(distance);
  }

  if( distance > distMin) {
    avance();
  }else {
    recule();
  }
}

void avance(){
  for( int n=0;n<4;n++){
     servoAvant.write(avant[2*n]);
     servoArriere.write(avant[(2*n)+1]);
     delay(350);
  }
}

void recule(){
  for( int n=0;n<4;n++){
     servoAvant.write(arriere[2*n]);
     servoArriere.write(arriere[(2*n)+1]);
     delay(350);
  }
}

int quelleDistance(){
  delay(100);
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  return cm;
}

