#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid = "Medialab";
const char* password = "Mediacollege";
const char* server = "22084.hosts.ma-cloud.nl";
String path = "/ESP/light.json";
static const uint8_t wifiConnecting = 5;
static const uint8_t wifiOk = 4;

void setup() {
  Serial.begin(115200);
  pinMode(wifiConnecting, OUTPUT);
  pinMode(wifiOk, OUTPUT);
  digitalWrite(wifiConnecting, LOW);
  digitalWrite(wifiOk, LOW);
  delay(10);

  /*pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);*/
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {

    wifiConnect();
  }

  httpRequest();
}

void httpRequest() {
  delay(2000);
  WiFiClient client;

  if (client.connect(server, 80)) {
    client.println("GET " + path + " HTTP/1.1");
    client.println("HOST: " + String(server));
    client.println("Connection: keep-alive");
    client.println("");
  } else {
    Serial.println("Webserver did not respond");
    return;
  }

  while (client.connected()) {
    if (client.available()) {
      char str = client.read();
      Serial.print(str);
    }
  }

  Serial.println("");
}

void wifiConnect() {
  int ledState = 0;

  digitalWrite(wifiOk, LOW);
  digitalWrite(wifiConnecting, HIGH);

  Serial.println("");
  Serial.print("Connecting to ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    if (ledState == 0) ledState = 1;
    else ledState = 0;

    digitalWrite(wifiConnecting, ledState);
  }

  Serial.println("");
  Serial.print("WiFi connected, IP adress: ");
  Serial.print(WiFi.localIP());

  WiFi.printDiag(Serial);

  digitalWrite(wifiConnecting, LOW);
  digitalWrite(wifiOk, HIGH);
}

