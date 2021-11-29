#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <WiFiManager.h> // automatyczny manager wifi
WiFiManager wifiManager;

#include "strona.h"

const int red_pin = D5;
const int green_pin = D6;
const int blue_pin = D7;

const float RED_CALIBRATE = 1;
const float GREEN_CALIBRATE = 1;
const float BLUE_CALIBRATE = 1;

long int fade_goTime;
int fade_break = 20;

String color = "sekwencja RGB (szybka)";
ESP8266WebServer server(80);

int redVal = 0;
int grnVal = 0;
int bluVal = 0;

int prevR = redVal;
int prevG = grnVal;
int prevB = bluVal;

bool fade_enable = true;

void handleRoot() {
  Serial.println("Obslugiwanie klienta");

  String s = STRONA;
  s.replace("@@color@@", color);
  s.replace("@@IP_ADDR@@", WiFi.localIP().toString());

  server.send(200, "text/html", s);
}

void fade() {
  if (fade_enable) {
    static unsigned int rgbColour[3] = {255, 0, 0};

    static int incColour = 1;
    static int decColour = 0;
    static int i = -1;

    i++;
    if (i >= 255) {
      i = 0;
      decColour ++;
      if (decColour > 2) decColour = 0;
      if (decColour == 2)  incColour = 0;
      else incColour = decColour + 1;
    }

    rgbColour[decColour] -= 1;
    rgbColour[incColour] += 1;

    setc(rgbColour[0], rgbColour[1],  rgbColour[2]);
    fade_goTime = millis() + fade_break;
  }
}

void off() {
  fade_enable = false;
  crossFade(0, 0, 0);
}

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue;
  if (step) {
    step = 1020 / step;
  }
  return step;
}

int calculateVal(int step, int val, int i) {
  if ((step) && i % step == 0) {
    if (step > 0) {
      val += 1;
    }
    else {
      val -= 1;
    }
  }
  if (val > 255) {
    val = 255;
  }
  else if (val < 0) {
    val = 0;
  }
  return val;
}

void crossFade(unsigned int r, unsigned int g, unsigned int b) {
  int stepR = calculateStep(prevR, r);
  int stepG = calculateStep(prevG, g);
  int stepB = calculateStep(prevB, b);

  for (int i = 0; i <= 1020; i++) {
    redVal = calculateVal(stepR, redVal, i);
    grnVal = calculateVal(stepG, grnVal, i);
    bluVal = calculateVal(stepB, bluVal, i);
    if (i % 20 == 0) {
      setc(redVal, grnVal, bluVal);
    }
  }

  prevR = redVal;
  prevG = grnVal;
  prevB = bluVal;
}

void setc(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(red_pin, red * RED_CALIBRATE);
  analogWrite(green_pin, green * GREEN_CALIBRATE);
  analogWrite(blue_pin, blue * BLUE_CALIBRATE);
}


void handleReset() {
  Serial.println("Resetowanie ustawien");
  server.send(200, "text/plan", "Zresetowano ustawienia do stanu poczatkowego. Plytka zostanie zrestartowana i mozliwe bedzie ponowne przeprowadzenie poczatkowej konfiguracji");

  delay(500);
  WiFi.disconnect();
  wifiManager.resetSettings();
  ESP.restart();
}

void handleForm() {
  color = server.arg("color");

  if (color != "") {
    Serial.println("Orzymano kolor: " + color);

    if (color == "sekwencja RGB (wolna)") {
      Serial.println("Uruchamiam sekwencje RGB (wolna)");
      fade_break = 100;
      fade_enable = true;
      delay(200);
    }

    else if (color == "sekwencja RGB (szybka)") {
      Serial.println("Uruchamiam sekwencje RGB (szybka)");
      fade_break = 20;
      fade_enable = true;
      delay(200);
    }

    else if (color == "wyłączony") {
      Serial.println("Wylaczanie LED");
      off();
    }

    else {
      fade_enable = false;

      String redval = color.substring(color.indexOf("r") + 1, color.indexOf("r") + 4);
      String greenval = color.substring(color.indexOf("g") + 1, color.indexOf("g") + 4);
      String blueval = color.substring(color.indexOf("b") + 1, color.indexOf("b") + 4);

      Serial.println("Uzywanie kolorow:");
      Serial.print("R: " + String(redval.toInt()));
      Serial.print(", G: " + String(greenval.toInt()));
      Serial.println(", B: " + String(blueval.toInt()));
      crossFade(redval.toInt(), greenval.toInt(), blueval.toInt());
    }
  }

  else {
    Serial.println("Nie otrzymano koloru");
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Jakims cudem przegladarka Cie nie przekierowała - wroc do poprzedniej strony :p");
}

void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  fade_goTime = millis();
  fade();
  
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  bool res = wifiManager.autoConnect("Szyldzikowy LED Manager");
  if (!res) {
    Serial.println("Blad laczenia z Wi-Fi!");
    delay(1000);
    ESP.restart();
  }
  else {
    Serial.println("Polaczono z Wi-Fi");
  }

  IPAddress myIP = WiFi.softAPIP();
  Serial.println(WiFi.localIP());

  if (!MDNS.begin("szyldzik")) {
    Serial.println("Blad w ustawianiu mDNS!");
    delay(1000);
  }
  MDNS.addService("http", "tcp", 80);
  MDNS.addService("http", "tcp", 443);
  Serial.println("Ustawiono mDNS");

  server.on("/", handleRoot);
  server.on("/form", handleForm);
  server.on("/reset", handleReset);
  server.begin();
}

void loop() {
  if (millis() >= fade_goTime) fade();
  
  server.handleClient();
  MDNS.update();
}
