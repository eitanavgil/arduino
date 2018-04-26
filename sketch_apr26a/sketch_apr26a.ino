#include <ButtonDebounce.h>
int a = 0;
ButtonDebounce button(10, 10);
void buttonChanged(int state){
  if(state == 0 ) {
    Serial.println("DOWN: " + String(a) );
    a++;
  }else{
    Serial.println("UP: ");
  }
  
}


void setup() {
  Serial.begin(9600);
  button.setCallback(buttonChanged);
}

void loop() {
  button.update();
}
