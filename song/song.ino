const int c = 261;

const int buzzerPin = 8;


void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  beep(500, 100);
  delay(1000);
    beep(-600, 3000);
      delay(1000);
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);


}
