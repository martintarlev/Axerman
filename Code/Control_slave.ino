#include <esp_now.h>
#include <WiFi.h>
#define Ain1 4
#define Ain2 16
#define Ain3 17
#define Ain4 5
#define Bin1 27
#define Bin2 26
#define Bin3 25
#define Bin4 33
#define bat_on 19
#define Boost 18
int x_value;
int y_value;
int ON_bat;
int bost;

//Must match the sender structure
typedef struct struct_message {
  int Pot_x;
  int Pot_y;
  int ON;
  int boost;
} struct_message;

struct_message message;


void data_receive(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&message, incomingData, sizeof(message));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Integer: ");
  Serial.println(message.Pot_y);
  Serial.print("Character: ");
  Serial.println(message.Pot_x);
  Serial.println();
  x_value = message.Pot_x;
  y_value = message.Pot_y;
  ON_bat = message.ON;
  bost = message.boost;
}
 
void setup() {
 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(data_receive);
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(Ain3, OUTPUT);
  pinMode(Ain4, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(bat_on, OUTPUT);
  pinMode(Boost, OUTPUT);
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

if (x_value == 0 & y_value == 0) 

  {
    
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, LOW);
    digitalWrite(Ain3, LOW);
    digitalWrite(Ain4, LOW);
    digitalWrite(Bin1, LOW);
    digitalWrite(Bin2, LOW);
    digitalWrite(Bin3, LOW);
    digitalWrite(Bin4, LOW);
  }
  if (x_value == 1 & y_value == 0) 
  {
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, HIGH);
    digitalWrite(Ain3, LOW);
    digitalWrite(Ain4, HIGH);
    digitalWrite(Bin1, LOW);
    digitalWrite(Bin2, HIGH);
    digitalWrite(Bin3, LOW);
    digitalWrite(Bin4, HIGH);
  }
 if (x_value == 2 & y_value == 0) 
  {
    digitalWrite(Ain1, HIGH);
    digitalWrite(Ain2, LOW);
    digitalWrite(Ain3, HIGH);
    digitalWrite(Ain4, LOW);
    digitalWrite(Bin1, HIGH);
    digitalWrite(Bin2, LOW);
    digitalWrite(Bin3, HIGH);
    digitalWrite(Bin4, LOW);
  }
  if (y_value == 1 & x_value == 0) 
  {
    
    digitalWrite(Ain1, LOW);
    digitalWrite(Ain2, HIGH);
    digitalWrite(Ain3, LOW);
    digitalWrite(Ain4, HIGH);
    digitalWrite(Bin1, HIGH);
    digitalWrite(Bin2, LOW);
    digitalWrite(Bin3, HIGH);
    digitalWrite(Bin4, LOW);
  }
  if (y_value == 2 & x_value == 0) 
  {
    digitalWrite(Ain1, HIGH);
    digitalWrite(Ain2, LOW);
    digitalWrite(Ain3, HIGH);
    digitalWrite(Ain4, LOW);
    digitalWrite(Bin1, LOW);
    digitalWrite(Bin2, HIGH);
    digitalWrite(Bin3, LOW);
    digitalWrite(Bin4, HIGH);
  } 
 if (y_value == 0) 
 {
   
  }
if (bost == 0 & ON_bat == 0)
  {
    digitalWrite(Boost, LOW);
    digitalWrite(bat_on, LOW);
  }
  if (bost == 0 & ON_bat == 1)
  {
    digitalWrite(Boost, LOW);
    digitalWrite(bat_on, HIGH);
  }
  if (bost == 1 & ON_bat == 1)
  {
    digitalWrite(Boost, LOW);
    digitalWrite(bat_on, HIGH);
  }
  if (bost == 1 & ON_bat == 0)
  {
    digitalWrite(Boost, HIGH);
    digitalWrite(bat_on, LOW);
  }
}