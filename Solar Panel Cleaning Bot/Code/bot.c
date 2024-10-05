#define BLYNK_TEMPLATE_ID "YourTemplateID" // Replace with your Blynk template ID
#define BLYNK_TEMPLATE_NAME "YourTemplateName" // Replace with your Blynk template name
#define BLYNK_AUTH_TOKEN "YourAuthToken" // Replace with your Blynk Auth Token

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define relay pins
#define RELAY_FORWARD D1
#define RELAY_BACKWARD D2
#define RELAY_RIGHT D3
#define RELAY_LEFT D4
#define RELAY_CLEAN D5

// Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "your_SSID"; // Replace with your Wi-Fi SSID
char pass[] = "your_PASSWORD"; // Replace with your Wi-Fi Password

void setup() {
    // Initialize Serial
    Serial.begin(115200);
    
    // Blynk setup
    Blynk.begin(auth, ssid, pass);

    // Set relay pins as outputs
    pinMode(RELAY_FORWARD, OUTPUT);
    pinMode(RELAY_BACKWARD, OUTPUT);
    pinMode(RELAY_RIGHT, OUTPUT);
    pinMode(RELAY_LEFT, OUTPUT);
    pinMode(RELAY_CLEAN, OUTPUT);

    // Initialize all relays to OFF
    digitalWrite(RELAY_FORWARD, HIGH);
    digitalWrite(RELAY_BACKWARD, HIGH);
    digitalWrite(RELAY_RIGHT, HIGH);
    digitalWrite(RELAY_LEFT, HIGH);
    digitalWrite(RELAY_CLEAN, HIGH);
}

// Forward
BLYNK_WRITE(V0) { 
    int value = param.asInt();
    if (value == 1) {
        digitalWrite(RELAY_FORWARD, LOW); // Relay ON
    } else {
        digitalWrite(RELAY_FORWARD, HIGH); // Relay OFF
    }
}

// Backward
BLYNK_WRITE(V1) { 
    int value = param.asInt();
    if (value == 1) {
        digitalWrite(RELAY_BACKWARD, LOW); // Relay ON
    } else {
        digitalWrite(RELAY_BACKWARD, HIGH); // Relay OFF
    }
}

// Left
BLYNK_WRITE(V2) { 
    int value = param.asInt();
    if (value == 1) {
        digitalWrite(RELAY_LEFT, LOW); // Relay ON
    } else {
        digitalWrite(RELAY_LEFT, HIGH); // Relay OFF
    }
}

// Right
BLYNK_WRITE(V3) { 
    int value = param.asInt();
    if (value == 1) {
        digitalWrite(RELAY_RIGHT, LOW); // Relay ON
    } else {
        digitalWrite(RELAY_RIGHT, HIGH); // Relay OFF
    }
}

// Clean
BLYNK_WRITE(V4) { 
    int value = param.asInt();
    if (value == 1) {
        digitalWrite(RELAY_CLEAN, LOW); // Relay ON
    } else {
        digitalWrite(RELAY_CLEAN, HIGH); // Relay OFF
    }
}

void loop() {
    Blynk.run(); // Run Blynk
}
