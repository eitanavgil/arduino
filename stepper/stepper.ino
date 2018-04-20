#include "Servo.h"

Servo servo1;
int delayme = 10;

void setup() {
  servo1.attach(9);
  servo1.write(0);
}

void loop() {
//  for (int i; i < 180; i++) {
//    servo1.write(i);
//    delay(delayme);
//  }
//  for (int i; i < 180; i++) {
//    servo1.write(180 - i);
//    delay(delayme);
//  }


}

