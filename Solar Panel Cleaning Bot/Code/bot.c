#define BLYNK_TEMPLATE_ID "TMPL34wUlHQHg"                   // Define Blynk template ID
#define BLYNK_TEMPLATE_NAME "agribot"                       // Define Blynk template name
#define BLYNK_AUTH_TOKEN "TuqqyR4HDs4ahmmTLZ2ak2Nw2ZBm0rVD" // Define Blynk authorization token

#include <ESP8266WiFi.h>        // Include ESP8266 WiFi library
#include <BlynkSimpleEsp8266.h> // Include Blynk library for ESP8266
#include <Servo.h>              // Include Servo library

const int sensor_pin = A0;      // Define sensor pin for soil moisture
char auth[] = BLYNK_AUTH_TOKEN; // Blynk auth token
char ssid[] = "realme";         // WiFi SSID
char pass[] = "12345678";       // WiFi Password

BlynkTimer Timer;  // Timer for Blynk
Servo servo1;      // Create a Servo object
int servoPin = D4; // Define pin for the servo motor

// Control for LED and servos based on Blynk virtual pins
BLYNK_WRITE(V0)
{
    int value = param.asInteger(); // Get the value from the button
    Serial.println(value);         // Print value to Serial Monitor
    if (value == 1)
    {                          // If button is pressed
        digitalWrite(D5, LOW); // Turn ON LED
        Serial.println("LED ON11");
    }
    else
    {
        digitalWrite(D5, HIGH); // Turn OFF LED
        Serial.println("LED OFF1");
    }
}

BLYNK_WRITE(V1)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        digitalWrite(D6, LOW);
        Serial.println("LED ON2");
    }
    else
    {
        digitalWrite(D6, HIGH);
        Serial.println("LED OFF2");
    }
}

BLYNK_WRITE(V2)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        digitalWrite(D7, LOW);
        Serial.println("LED ON3");
    }
    else
    {
        digitalWrite(D7, HIGH);
        Serial.println("LED OFF3");
    }
}

BLYNK_WRITE(V3)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        digitalWrite(D8, LOW);
        Serial.println("LED ON4");
    }
    else
    {
        digitalWrite(D8, HIGH);
        Serial.println("LED OFF4");
    }
}

BLYNK_WRITE(V5)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        digitalWrite(D2, LOW);
        Serial.println("LED ON5");
    }
    else
    {
        digitalWrite(D2, HIGH);
        Serial.println("LED OFF5");
    }
}

BLYNK_WRITE(V4)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        digitalWrite(D3, LOW);
        Serial.println("LED ON6");
    }
    else
    {
        digitalWrite(D3, HIGH);
        Serial.println("LED OFF6");
    }
}

BLYNK_WRITE(V7)
{
    int value = param.asInteger();
    Serial.println(value);
    if (value == 1)
    {
        servo1.write(180); // Move servo to 180 degrees
        delay(1000);       // Wait for 1 second
    }
    else
    {
        servo1.write(0); // Move servo to 0 degrees
        delay(1000);     // Wait for 1 second
    }
}

// Function to read soil moisture and send to Blynk
void sendSensor()
{
    float moisture_percentage;
    moisture_percentage = (100.00 - (analogRead(sensor_pin) / 1023.00) * 100.00); // Calculate moisture percentage
    Serial.print("Soil Moisture (in Percentage) = ");
    Serial.println(moisture_percentage);
    Blynk.virtualWrite(V6, moisture_percentage); // Send moisture percentage to Blynk
    delay(1000);                                 // Wait for 1 second
}

void setup()
{
    Serial.begin(115200);          // Start Serial communication
    Blynk.begin(auth, ssid, pass); // Connect to Blynk
    pinMode(D5, OUTPUT);           // Set LED pins as output
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);

    // Initialize LEDs to OFF
    digitalWrite(D5, HIGH);
    digitalWrite(D6, HIGH);
    digitalWrite(D7, HIGH);
    digitalWrite(D8, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);

    servo1.attach(servoPin); // Attach servo to pin
}

void loop()
{
    Blynk.run();  // Run Blynk to maintain connection
    sendSensor(); // Call sendSensor function to send moisture data
}
