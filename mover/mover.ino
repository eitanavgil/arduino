#include <PMButton.h>

/* 
 *  GAME 1 - competition between 2 opponents on how quickly they
 *  click. There are 2 buttons to each opponent, each moves the dot to
 *  a specific direction, every opponent is tryng to get the dot to
 *  his/her corner. Opponent that got to his corner wins. 
 */

//coordinates data structure for board. Has X and Y
struct Coordinates {
    int x;
    int y;
};

/*
 The game needs to initiate the dot in the center, however, the board has even numbers of rows
 and columns so it will start with 2x2 pixes on the center. After first move it will become a single led.
 */
Coordinates position = { 4.5 , 16.5 };


// define board dimensions
int board[32][9];

bool debugMode = false; 

// Each button has an even number. 
// The button correlating light pin wil be the following odd number
// E.G. Yellow pin 7 is the button input, therefore number 8 is the output yellow light.

const int GREEN = 1;
const int BLUE = 3;
const int RED = 5;
const int YELLOW = 7;

// Optimize init state 
bool hasStarted = false;

PMButton button1(RED)

void setup() {
  Serial.begin(9600);
  // defining buttons and buttons lights according to convention
  pinMode(RED, INPUT);
  pinMode(RED+1, OUTPUT);
  pinMode(GREEN, INPUT);
  pinMode(GREEN+1, OUTPUT);
  pinMode(BLUE, INPUT);
  pinMode(BLUE+1, OUTPUT);
  pinMode(YELLOW, INPUT);
  pinMode(YELLOW+1, OUTPUT);
}

void loop() {


}

// get the board selected
//Coordinates getSelectedLed (){
// return new Coordinates;
//}
