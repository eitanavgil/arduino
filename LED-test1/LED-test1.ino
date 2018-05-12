#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <ButtonDebounce.h>

//how many chained LED 8x8 matrix
#define MAX_DEVICES 4
#define CLK_PIN 13
#define DATA_PIN 11
#define CS_PIN 10

ButtonDebounce button1(2, 10);
ButtonDebounce button2(3, 10);

MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);

int x = 20;
void button1Changed(int state){
  if(state == 0 ) {
    mx.clear();
    x=x-1;
    mx.setPoint(0, x, true);
  }
}

void button2Changed(int state){
  if(state == 0 ) {
    mx.clear();
    x=x+1;
    mx.setPoint(0, x, true);
  }
}

// Hardware setup

void setup() {
  Serial.begin(9600);
  button1.setCallback(button1Changed);
  button2.setCallback(button2Changed);

  mx.begin();
  mx.setPoint(1, x, true);
  Serial.println(String(x) );
}

void loop() {
  button1.update();
  button2.update();
}
