#define JoyX_value  A6
#define JoyY_value  A7

int JoyX = 0;
int JoyY = 0;

void setup() {
  Serial.begin(9600) ;
}

void loop() {
  JoyX = analogRead(JoyX_value);
  JoyY = analogRead(JoyY_value);

  Serial.print("x = ");
  Serial.print(JoyX);
  Serial.print(", y = ");
  Serial.println(JoyY);
  delay(200);
}