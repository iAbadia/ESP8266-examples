#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

/* WIFI */
const char* ssid     = "...";
const char* password = "...";

/* WebServer */
ESP8266WebServer server(80);
const char* host_name = "esp8266";

void setup() {
  // Serial
  Serial.begin(115200);
  
  // mDNS/DNS-SD
  Serial.println("mDNS... ");
  if (MDNS.begin(host_name)) {
    MDNS.addService("http", "tcp", 80);
    Serial.println(" [+] MDNS responder ready (esp8266)");
  } else {
    Serial.println(" [-] MDNS responder failed.");
  }

  // WebServer
  server.on("/", handle_root);
  server.onNotFound(handle_not_found);
  server.begin();
}

void loop() {
  server.handleClient();
  delay(50);
}

void handle_root() {
  server.send(200, "text/plain", "esp8266 is up n' running!");
}

void handle_not_found() {
  server.send(404, "text/plain", "Not found :(");
}

