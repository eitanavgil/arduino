int potPin = 8;

void setup() {
  pinMode(potPin, OUTPUT);
}

void loop() {
  analogWrite(potPin, HIGH);

}                      
