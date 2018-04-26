#include <PMButton.h>
PMButton button1(2);
int i = 0;
int prev = 0;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);

  button1.begin();
  button1.debounce(10);//Default is 10 milliseconds
  // button1.dcGap(1000);//Time between clicks for Double click. Default is 200 milliseconds
  //  button1.longHoldTime(8000);//Default is 5 seconds
}
void loop() {
  int btnCode;
  button1.checkSwitch();
  if (button1.released()) {
    btnCode = 1;
    if(prev ==  btnCode){
      Serial.println( "released >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "released" );
  }
  else if (button1.clicked()) {
    btnCode = 2;
    if(prev ==  btnCode){
      Serial.println( "clicked >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "clicked" );
  }
  else if (button1.doubleClicked()) {
    btnCode = 3;
    if(prev ==  btnCode){
      Serial.println( "doubleClicked >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "doubleClicked" );
  }
  else if (button1.pressed()) {
    btnCode = 4;
    if(prev ==  btnCode){
      Serial.println( "pressed >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "pressed" );
  }
  else if (button1.heldLong()) {
    btnCode = 5;
    if(prev ==  btnCode){
      Serial.println( "heldLong >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "heldLong" );
  }
  else if (button1.held()) {
    btnCode = 6;
    if(prev ==  btnCode){
      Serial.println( "held >>>>>>>>>>>>>>" );
    }
    prev = btnCode;
    Serial.println( "held" );
  }



  // if(i>5){
  // } else {
  // }
  // digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  // delay(500);                       // wait for a second
  // digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  // delay(500);
}
