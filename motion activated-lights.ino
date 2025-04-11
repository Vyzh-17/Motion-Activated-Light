#include "thingProperties.h"

#define PIR_PIN 13
#define LED_PIN 2

unsigned long lastMotionTime = 0;
const unsigned long lightDuration = 60000; // 1 minute

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  if (autoModeCloud) {
    int motion = digitalRead(PIR_PIN);

    if (motion == HIGH) {
      Serial.println("Motion detected!");
      digitalWrite(LED_PIN, HIGH);
      lastMotionTime = millis();
    }

    if (millis() - lastMotionTime > lightDuration) {
      digitalWrite(LED_PIN, LOW);
    }
  }
}

// Callback when 'led' variable changes
void onLedChange() {
  if (!autoModeCloud) { // Only control LED in manual mode
    if (led) {
      Serial.println("Manual: LED ON");
      digitalWrite(LED_PIN, HIGH);
    } else {
      Serial.println("Manual: LED OFF");
      digitalWrite(LED_PIN, LOW);
    }
  }
}

// Callback when 'autoModeCloud' variable changes
void onAutoModeCloudChange() {
  if (autoModeCloud) {
    Serial.println("Switched to AUTO mode (Motion)");
  } else {
    Serial.println("Switched to MANUAL mode (Cloud)");
  }
}
