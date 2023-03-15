#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t Receiver_Address1[] = {0x30, 0xAE, 0xA4, 0x01, 0x3C, 0x5C};

typedef struct struct_message {
  int integer;
  char character[100];
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
 
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_send_cb(data_sent);
   
  esp_now_peer_info_t peerInfo ={};
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  memcpy(peerInfo.peer_addr, Receiver_Address1, 6);
  Serial.println("test2");
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("test3");
    Serial.println("Failed to add peer");
    Serial.println("test4");
    return;
  }
}
 
void loop() {
  message.integer = random(0,50);
 strcpy(message.character, "Welcome to Microcontrollerslab! This is test example.");
 
  esp_err_t outcome = esp_now_send(0, (uint8_t *) &message, sizeof(struct_message));
   
  if (outcome == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(2000);
}