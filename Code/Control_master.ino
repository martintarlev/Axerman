#include <esp_now.h>
#include <WiFi.h>
#define xjoy 32
#define yjoy 35
#define bat_on 19
#define Boost 18


// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t Receiver_Address1[] = {0x30, 0xAE, 0xA4, 0x06, 0x25, 0x08};

typedef struct struct_message {
  int Pot_x=0;
  int Pot_y=0;
  int ON;
  int boost;
} struct_message;

struct_message message;

void data_sent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char address[18];
  Serial.print("Sent to: ");
  snprintf(address, sizeof(address), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(address);
  Serial.print(" status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  pinMode(xjoy, INPUT);
  pinMode(yjoy, INPUT);
  pinMode(bat_on, INPUT);
  pinMode(Boost, INPUT);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(data_sent);

  esp_now_peer_info_t peerInfo ={};
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, Receiver_Address1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  esp_err_t outcome = esp_now_send(0, (uint8_t *) &message, sizeof(struct_message));
  int potValue_x = analogRead(xjoy); // Read potentiometer value
  int potValue_y = analogRead(yjoy); // Read potentiometer value
  int batValue = digitalRead(bat_on);
  int boostValue = digitalRead(Boost);

  if (batValue == HIGH) 
  {
    message.ON = 1;
  }  
  else
  {
    message.ON = 0;
  } 
  if (potValue_x < 1500  ) 
  {
    message.Pot_x = 1;
  }
  if (potValue_x > 2200) 
  {
    message.Pot_x = 2;
  }
 if (potValue_x < 2200 & potValue_x > 1500) 
  {
    message.Pot_x = 0;
  }
  if (potValue_y < 1500  ) 
  {
    message.Pot_y = 1;
  }
  if (potValue_y > 2200) 
  {
    message.Pot_y = 2;
  }
 if (potValue_y < 2200 & potValue_y > 1500) 
  {
   message.Pot_y = 0;
  }
  if (boostValue == HIGH) 
  {
    message.boost = 1;
  }  
  else
  {
    message.boost = 0;
  } 
  if (outcome == ESP_OK)
  {
    Serial.println("Sent with success");
  }
 else 
  {
    Serial.println("Error sending the data");
  }
  Serial.println(message.Pot_x);
  Serial.println(potValue_x);
  Serial.println(message.Pot_y);
  Serial.println(potValue_y);
  Serial.println(message.ON);
  Serial.println(batValue);
  Serial.println(message.boost);
  Serial.println(boostValue);
  
}