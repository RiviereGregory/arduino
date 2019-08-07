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

  if (val == 0xFF18E7) {
    digitalWrite(pinLed, HIGH);
  }
  if (val == 0xFF30CF) {
    digitalWrite(pinLed, LOW);
  }

  if (val == 0xFF7A85) {
    digitalWrite(pinLed3, HIGH);
  }
  if (val == 0xFF5AA5) {
    digitalWrite(pinLed3, LOW);
  }

}
