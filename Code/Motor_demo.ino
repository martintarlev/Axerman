#define Ain1 25
#define Ain2 33
#define Ain3 27
#define Ain4 26
#define xjoy 32
#define Bin1 4
#define Bin2 16
#define Bin3 17
#define Bin4 5 
#define yjoy 35

int rotDirection = 0;
int stop = 1;


void setup() {
  Serial.begin(115200);
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(Ain3, OUTPUT);
  pinMode(Ain4, OUTPUT);
  pinMode(xjoy, INPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(yjoy, INPUT);
  digitalWrite(Ain1, LOW);
  digitalWrite(Ain2, LOW);
  digitalWrite(Ain3, LOW);
  digitalWrite(Ain4, LOW);
   digitalWrite(Bin1, LOW);
  digitalWrite(Bin2, LOW);
  digitalWrite(Bin3, LOW);
  digitalWrite(Bin4, LOW);
}

void loop() {
  int potValue_x = analogRead(xjoy); // Read potentiometer value
  int potValue_y = analogRead(yjoy); // Read potentiometer value



  if (potValue_x < 1500  ) {
    digitalWrite(Ain1, HIGH);
    digitalWrite(Ain2, LOW);
    digitalWrite(Ain3, HIGH);
    digitalWrite(Ain4, LOW);
    rotDirection = 1;
    delay(20);
    stop = 1;
  }
  if (potValue_x > 2200) {
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, HIGH);
    digitalWrite(Ain3, LOW);
    digitalWrite(Ain4, HIGH);
    rotDirection = 0;
    delay(20);
   stop = 1;
}
 if (potValue_x < 2200 & potValue_x > 1500) {
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, LOW);
    digitalWrite(Ain3, LOW);
    digitalWrite(Ain4, LOW);
    stop = 0;
  
}




  if (potValue_y < 1500  ) {
    digitalWrite(Bin1, HIGH);
    digitalWrite(Bin2, LOW);
    digitalWrite(Bin3, HIGH);
    digitalWrite(Bin4, LOW);
    rotDirection = 1;
    delay(20);
    stop = 1;
  }
  if (potValue_y > 2200) {
    digitalWrite(Bin1, LOW);
    digitalWrite(Bin2, HIGH);
    digitalWrite(Bin3, LOW);
    digitalWrite(Bin4, HIGH);
    rotDirection = 0;
    delay(20);
   stop = 1;
}
 if (potValue_y < 2200 & potValue_y > 1500) {
    digitalWrite(Bin1, LOW);
    digitalWrite(Bin2, LOW);
    digitalWrite(Bin3, LOW);
    digitalWrite(Bin4, LOW);
    stop = 0;
  
}
  Serial.println(potValue_x);
  Serial.println(stop);
  Serial.println(potValue_y);
  Serial.println(rotDirection);
}