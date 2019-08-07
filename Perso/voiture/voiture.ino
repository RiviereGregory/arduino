#include <NewPing.h>

int pin1Moteur1 = 12;
int pin2Moteur1 = 8;
int pinPMoteur1 = 11;
int pin1Moteur2 = 2;
int pin2Moteur2 = 4;
int pinPMoteur2 = 5;
int TRIG_PIN = 10;
int ECHO_PIN = 9;
int DIST_MAX = 200;
int i = 90;
int distActuelle = 0;
int cm;
NewPing sonar(TRIG_PIN,ECHO_PIN,DIST_MAX);

void setup() {
  pinMode(pin1Moteur1,OUTPUT);
  pinMode(pin2Moteur1,OUTPUT);
  pinMode(pinPMoteur1,OUTPUT);
  pinMode(pin1Moteur2,OUTPUT);
  pinMode(pin2Moteur2,OUTPUT);
  pinMode(pinPMoteur2,OUTPUT);

}

void loop() {
  distActuelle = lectureDistance();

  if (distActuelle > 20){
    avance();
  }

  if (distActuelle < 20){
    recule();
    tourneDroite();
  }
  delay(300);
}

void dirMoteur(int moteur, int sens, int pc){
  int pin1,etat1,pin2,etat2,pinP,puissance;

  if(moteur == 1){
    pin1 = pin1Moteur1;
    pin2 = pin2Moteur1;
    pinP = pinPMoteur1;
  } else {
    pin1 = pin1Moteur2;
    pin2 = pin2Moteur2;
    pinP = pinPMoteur2;
  }

  if (sens == 1){
    etat1 = 1;
    etat2 = 0;
  } else if (sens == -1){
    etat1 = 0;
    etat2 = 1;
  } else {
    etat1 = 0;
    etat2 = 0;
  }

  puissance = map(pc,0,100,0,255);
  analogWrite(pinP,puissance);
  digitalWrite(pin1,etat1);
  digitalWrite(pin2,etat2);
}

void avance(){
  dirMoteur(1,1,100);
  dirMoteur(2,1,100);
}

void recule(){
  dirMoteur(1,0,100);
  dirMoteur(2,0,100);
  delay(2000);
  dirMoteur(1,-1,100);
  dirMoteur(2,-1,100);
}

void tourneDroite(){
  delay(1000);
  dirMoteur(1,-1,100);
  dirMoteur(2,0,0);
  delay(1000);
  dirMoteur(1,-1,100);
  dirMoteur(2,1,50);
  delay(1000);
}

int lectureDistance(){
  delay(70);
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  if (cm == 0){
    lectureDistance();
  }else {
    Serial.println(cm);
    return cm;
  }  
}
