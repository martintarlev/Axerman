#define in1 25
#define in2 33
#define xjoy 32

int rotDirection = 0;
int stop = 1;

void setup() {
  Serial.begin(115200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(xjoy, INPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  int potValue = analogRead(xjoy); // Read potentiometer value
 


  // If button is pressed - change rotation direction
  if (potValue < 1500  ) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    rotDirection = 1;
    delay(20);
    stop = 1;
  }
  // If button is pressed - change rotation direction
  if (potValue > 2200) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    rotDirection = 0;
    delay(20);
   stop = 1;
}
 if (potValue < 2200 & potValue > 1500) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    stop = 0;
  
}
  Serial.println(potValue);
  Serial.println(stop);
  Serial.println(rotDirection);
}