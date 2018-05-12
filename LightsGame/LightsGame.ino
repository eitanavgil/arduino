#include <ButtonDebounce.h>
// Y R    G B

ButtonDebounce button1(2, 10);
ButtonDebounce button2(4, 10);
ButtonDebounce button3(6, 10);
ButtonDebounce button4(8, 10);
int YELLOW = 2;
int YELLOW_L = 3;
int RED = 4;
int RED_L = 5;
int GREEN = 6;
int GREEN_L = 7;
int BLUE = 8;
int BLUE_L = 9;

boolean running = false;

int light1;
int light2;

int scoreLeft = 0;
int scoreRight = 0;

//YELLOW
void button1Changed(int state){
  if(state == 0 ) {
    checkClick(2);
  }
}
//RED
void button2Changed(int state){
  if(state == 0 ) {
    checkClick(4);
  }
}
//GREEN
void button3Changed(int state){
  if(state == 0 ) {
    checkClick(6);
  }
}
//BLUE
void button4Changed(int state){
  if(state == 0 ) {
    checkClick(8);
  }
}

void newRound(){
  // check of one of the players got to 10
  if (scoreLeft == 10){
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    delay(10000);
  }

  if (scoreRight == 10){
    digitalWrite(7, HIGH);
    digitalWrite(7, HIGH);
    delay(10000);
  }

  running = false;
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
}

void checkClick(int n){
  if(n == light1){
    //player 1 got it right
    scoreLeft ++;
    correct(n);
  }else if(n == light2){
    //player 2 got it right
    scoreRight ++;
    correct(n);
  }else if (n == 2 || n==4 ){
    //player 1 got wrong
    scoreLeft --;
    wrong(n);
  }else{
    //player 2 got wrong
    scoreRight --;
    wrong(n);
  }

}
//correct - blink 3 times slowly
void correct(int n){
  // loop from the lowest pin to the highest:
  for (int i = 0; i < 3; i++) {
    // turn the pin on:
    digitalWrite(n+1, LOW);
    delay(700);
    // turn the pin off:
    digitalWrite(n+1, HIGH);
  }
  newRound();
}

//wrong - blink fast 50 times
void wrong(int n){
  for (int i = 0; i < 50; i++) {
    // turn the pin on:
    digitalWrite(n+1, LOW);
    delay(50);
    // turn the pin off:
    digitalWrite(n+1, HIGH);
  }
  newRound();
}

void resetGame(){
  newRound();
  light1 = 0;
  light2 = 0;
}

void setup() {
  Serial.begin(9600); //debug
  button1.setCallback(button1Changed);
  button2.setCallback(button2Changed);
  button3.setCallback(button3Changed);
  button4.setCallback(button4Changed);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  if(!running){
    int rnd = random(2);
    light1 = rnd*2; // 2 || 4
    light2 = light1+4; // 6 || 8
    running = true;
    delay(random(5000)+3000); //rndom 3-8 secsß
    digitalWrite(light1+1, HIGH); //+1 for the light
    digitalWrite(light2+1, HIGH);
  }
}
