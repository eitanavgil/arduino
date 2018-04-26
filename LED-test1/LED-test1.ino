#include <MD_MAX72xx.h>
#include <SPI.h>

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#include <MD_MAX72xx.h>
#include <SPI.h>


//how many chained LED 8x8 matrix
#define MAX_DEVICES 4
#define CLK_PIN 13
#define DATA_PIN 11
#define CS_PIN 10

// Hardware setup
MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);

int WAIT_TIME = 500;

void setup() {

  Serial.begin(9600);
  //configure pin 2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(4, OUTPUT);

  // put your setup code here, to run once:
  mx.begin();
  bounce();
}

void loop() {
  // put your main code here, to run repeatedly:

  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
//  Serial.println(sensorVal);
//  Serial.println(66);

  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == HIGH) {
    Serial.println('1');
    digitalWrite(4, LOW);
  } else {
    Serial.println('2');
    digitalWrite(4, HIGH);
  }


}


void bounce()
// Animation of a bouncing ball
{

  const int minC = 0;
  const int maxC = mx.getColumnCount() - 1;
  const int minR = 0;
  const int maxR = ROW_SIZE - 1;

  int  nCounter = 0;

  int  r = 0, c = 2;
  int8_t dR = 1, dC = 1;  // delta row and column

  mx.clear();

  while (nCounter++ < 120000)
  {
    Serial.println('3');
    mx.setPoint(r, c, false);
    r += dR;
    c += dC;
    mx.setPoint(r, c, true);
    delay(WAIT_TIME / 2);
    if ((r == minR) || (r == maxR))
      dR = -dR;
    if ((c == minC) || (c == maxC))
      dC = -dC;
  }
}
