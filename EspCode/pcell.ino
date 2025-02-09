#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include <SoftwareSerial.h>

// Wi-Fi Credentials
#define WIFI_SSID "RealmeNarzo"
#define WIFI_PASSWORD "tatabyebye"

// Firebase Configuration
#define FIREBASE_HOST "vc02-3c2c3-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "yPk1h9Efpuf0QUCnVk2jQWm9w9q3O98FMEzoOWgw"

// Relay Pins
const int relayPins[] = {D1, D2, D3, D4, D5, D6, D7, D8};

// VC02 UART
SoftwareSerial VC02Serial(D3, D4); // RX, TX (adjust pins as needed)

FirebaseData firebaseData;
FirebaseConfig config;
FirebaseAuth auth;

void setup() {
  Serial.begin(115200);
  VC02Serial.begin(9600);

  // Initialize relays
  for (int i = 0; i < 8; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], HIGH); // Turn off initially
  }

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected!");

  // Initialize Firebase
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH; // Use legacy_token here
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    String relayPath = "/relays/relay" + String(i+1);
    
    if (Firebase.getBool(firebaseData, relayPath)) {
      bool state = firebaseData.boolData();
      digitalWrite(relayPins[i], !state); // Invert logic if needed
    }
  }
  delay(100);
}