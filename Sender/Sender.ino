#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ESP-AP";
const char* password = "12345678";

ESP8266WebServer server(80);

#define Motor_PIN D3

bool buzzerActive = false;
unsigned long motorOnTime = 0;
unsigned long zeroStartTime = 0;
bool zeroReceived = false;

void handleRoot() {
  String msg = server.arg("plain");  // "1" or "0"
  Serial.print("Received: ");
  Serial.println(msg);

  if (msg == "1") {
    digitalWrite(Motor_PIN, HIGH);
    motorActive = true;
    motorOnTime = millis();
    zeroReceived = false;
    Serial.println("🔔 Machine ON");
  } 
  else if (msg == "0" && motorActive) {
    if (!zeroReceived) {
      zeroStartTime = millis();  // First time receiving 0
      zeroReceived = true;
    }
  }

  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);
  pinMode(Motor_PIN, OUTPUT);
  digitalWrite(Motor_PIN, LOW);

  WiFi.softAP(ssid, password);
  delay(100);
  Serial.println("📡 Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", HTTP_POST, handleRoot);
  server.begin();
  Serial.println("🟢 Web Server Running");
}

void loop() {
  server.handleClient();

  if (motorActive && zeroReceived) {
    if (millis() - zeroStartTime > 6000) {  // 6 seconds of "0"
      digitalWrite(Motor_PIN, LOW);
      motorActive = false;
      zeroReceived = false;
      Serial.println(" Machine OFF (0 held for 6 sec)");
    }
  }
}
