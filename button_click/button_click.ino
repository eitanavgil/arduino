#include <PMButton.h>
PMButton button1(2);
int i = 0;

void setup() {
  Serial.begin(9600);
   pinMode(7, OUTPUT);

  button1.begin();
//  button1.debounce(20);//Default is 10 milliseconds
    button1.dcGap(1);//Time between clicks for Double click. Default is 200 milliseconds
//  button1.holdTime(3000);//Default is 2 seconds
//  button1.longHoldTime(8000);//Default is 5 seconds
}
void loop() {
  button1.checkSwitch();
   if (button1.pressed()) {
    Serial.println( ++i );
  }

  if(i>3){
      digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
  } else {
      digitalWrite(7, HIGH);    // turn the LED off by making the voltage LOW

  }


  
}
