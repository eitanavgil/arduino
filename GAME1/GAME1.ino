#include <PMButton.h>

/* 
 *  GAME 1 - ompetition between 2 opponents on how quickly they 
 *  click. There are 2 buttons to each opponent, each moves the dot to
 *  a specific direction, every opponent is tring to get the dot to 
 *  his/her corner. Opponent that got to his corner wins. 
 */


/*
 * The game needs to initiate the dot in the center, however, the boar has even 
 */
int VERTICAL = 4.5;
int HORIZONTAL = 16.5;

bool debugMode = false; 

// Each button has an even number. 
// The button corolating light pin wil be the following odd number 
// E.G. Yellow pin 6 is the button input, therfore number 7 is the yellow button light. 

const int RED = 0;
const int GREEN = 2;
const int BLUE = 4;
const int YELLOW = 6;

// Optimize init state 
bool hasStarted = false;

PMButton button1(RED);

void setup() {
  Serial.begin(9600);
  pinMode(RED, INPUT);
  pinMode(GREEN, INPUT);
  pinMode(BLUE, INPUT);
  pinMode(YELLOW, INPUT);
}

void loop() {


}
