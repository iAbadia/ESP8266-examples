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
  /* Serial */
  Serial.begin(115200);
  
  /* mDNS/DNS-SD */
  Serial.println("mDNS... ");
  if (MDNS.begin(host_name)) {
    Serial.println(" [+] MDNS responder ready (esp8266)");
    // Service Advertiser
    MDNS.addService("http", "tcp", 80);
    Serial.println(" [+] Service Advertiser ready");
  } else {
    Serial.println(" [-] MDNS responder failed.");
  }

  /* WebServer */
  // Handler for root URI
  server.on("/", handle_root);
  // Another handler
  server.on("/validUri", handle_valid_uri);
  // Handler for not found resources
  server.onNotFound(handle_not_found);
  // Start WebServer
  server.begin();
}

void loop() {
  server.handleClient();
  delay(50);
}

void handle_root() {
  server.send(200, "text/plain", "esp8266 is up n' running!");
}

void handle_valid_uri() {
  String msg = "You accessed a valid URI with ";
  msg += server.args();
  msg += " arguments!"
  server.send(200, "text/plain", msg);
}

void handle_not_found() {
  server.send(404, "text/plain", "Not found :(");
}

