#include <ButtonDebounce.h>
int a = 0;

ButtonDebounce button1(2, 10);
ButtonDebounce button2(3, 10);

void button1Changed(int state){
  if(state == 0 ) {
    Serial.println(String(a++) );
  }
}
void button2Changed(int state){
  if(state == 0 ) {
    Serial.println(String(a--) );
  }
}

void setup() {
  Serial.begin(9600);
  button1.setCallback(button1Changed);
  button2.setCallback(button2Changed);
}

void loop() {
  button1.update();
  button2.update();
}
