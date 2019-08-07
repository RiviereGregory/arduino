#include <Servo.h>

Servo monServo1;
Servo monServo2;
int posiMoteur1 = 0;
int posiMoteur2 = 0;
int inputMoteur1 = 6;
int inputMoteur2 = 7;
int pinMoteur1 = 2;
int pinMoteur2 = 4;
boolean sensPositifMoteur1 = true;
boolean sensPositifMoteur2 = true;
int valMoteur1 = 0;
int valMoteur2 = 0;

void setup() {
  pinMode(inputMoteur1, INPUT);
  pinMode(inputMoteur2, INPUT);
  pinMode(pinMoteur1, OUTPUT);
  pinMode(pinMoteur2, OUTPUT);
  monServo1.attach(pinMoteur1);
  monServo2.attach(pinMoteur2);

}

boolean sensMoteur (boolean retour,int posiMoteur){
  if (posiMoteur == 0 && !retour){
      retour = true;
    }        
    if (posiMoteur == 90 && retour){
      retour = false;
    }
    return retour;
}

void loop() {
  valMoteur1 = digitalRead(inputMoteur1);
  valMoteur2 = digitalRead(inputMoteur2);
  if (valMoteur1 == HIGH){    
    sensPositifMoteur1 = sensMoteur(sensPositifMoteur1,posiMoteur1);    
    if (posiMoteur1 < 90 && sensPositifMoteur1){
      posiMoteur1++;
    }else  if (posiMoteur1 > 0 && !sensPositifMoteur1){
      posiMoteur1--;
    }    
    monServo1.write(posiMoteur1);
  }
  if (valMoteur2 == HIGH){    
    sensPositifMoteur2 = sensMoteur(sensPositifMoteur2,posiMoteur2);
    
    if (posiMoteur2 < 90 && sensPositifMoteur2){
      posiMoteur2++;
    }else  if (posiMoteur2 > 0 && !sensPositifMoteur2){
      posiMoteur2--;
    }        
    monServo2.write(posiMoteur2);    
  }
  delay(15);
}

