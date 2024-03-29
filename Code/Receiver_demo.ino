#include <esp_now.h>
#include <WiFi.h>

//Must match the sender structure
typedef struct struct_message {
  int integer;
  char character[100];
} struct_message;

struct_message message;


void data_receive(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&message, incomingData, sizeof(message));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Integer: ");
  Serial.println(message.integer);
  Serial.print("Character: ");
  Serial.println(message.character);
  Serial.println();
}
 
void setup() {
 
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(data_receive);
}
 
void loop() {

}