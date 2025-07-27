#include <ESP8266WiFi.h>

// WiFi credentials of the RECEIVER (AP mode)
const char* ssid = "ESP-AP";
const char* password = "12345678";
const char* host = "192.168.4.1";  // Receiver's IP

#define PAD_OUTPUT D2  // GPIO4, copper plate A
#define PAD_INPUT A0   // Analog input, copper plate B

int threshold = 50;
int lastState = -1;  // Unknown at start

void setup() {
  Serial.begin(115200);
  
  pinMode(PAD_OUTPUT, OUTPUT);
  digitalWrite(PAD_OUTPUT, HIGH);  // Constant 3.3V on plate A

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\n✅ Connected to ESP-AP");
}

void loop() {
  int value = analogRead(PAD_INPUT);
  Serial.print("Analog value: ");
  Serial.println(value);

  int currentState = (value > threshold) ? 1 : 0;

  if (currentState != lastState) {
    WiFiClient client;
    if (client.connect(host, 80)) {
      String data = String(currentState);
      client.println("POST / HTTP/1.1");
      client.println("Host: " + String(host));
      client.println("Content-Type: text/plain");
      client.println("Content-Length: " + String(data.length()));
      client.println();
      client.println(data);
      client.stop();
      Serial.print("Sent HTTP: ");
      Serial.println(data);
    } else {
      Serial.println("❌ Connection to AP failed");
    }
    lastState = currentState;
  }

  delay(200);
}
