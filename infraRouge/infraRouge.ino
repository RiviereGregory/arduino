#include <IRremote.h>

long val;
int IRpin = 10;
int pinLed = 4;
int pinLed3 = 3;

IRrecv irrecv(IRpin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed3, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results) == 1) {
    val = results.value;
    Serial.println(val, HEX);
    irrecv.resume();
  }
  // Pour determiner les val il faut mettre l'ide arduino en moniteur série
  // teleco 2
  if (val == 0xFF18E7) {
    digitalWrite(pinLed, HIGH);
  }
  // teleco 1
  if (val == 0xFF30CF) {
    digitalWrite(pinLed, LOW);
  }
  // teleco 3
  if (val == 0xFF7A85) {
    digitalWrite(pinLed3, HIGH);
  }
  // teleco 6
  if (val == 0xFF5AA5) {
    digitalWrite(pinLed3, LOW);
  }
  // teleco 0
  if (val == 0xFF6897) {
    digitalWrite(pinLed, LOW);
    digitalWrite(pinLed3, LOW);
  }
  // teleco 9
  if (val == 0xFF52AD) {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinLed3, HIGH);
  }

}
