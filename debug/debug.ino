const int btn1 = 7;
const int btn2 = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button1State = digitalRead(btn1);
  Serial.println(button1State == LOW );
}
