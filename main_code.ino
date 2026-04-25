/*
 * Project Name: SHIVA SURAKSHA (The Divine Shield)
 * Developed by: Gaddam Ganesh (10th Class Innovator)
 * Platform: Arduino Mega 2560
 * Mission: AI-Powered Pure Food and Organic Farming Guidance
 */

#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

// --- Pin Definitions ---
// Robot 1: Shuddhahara Chakshuvu Sensors
const int MQ136_GAS_PIN = A0;    // Chemical/Ripening detection
const int SPECTRAL_SENSOR_PIN = A1; // Placeholder for spectral analysis

// Robot 2: Kshetrajna Margadarshi Sensors
const int NPK_SOIL_PIN = A2;     // Soil nutrient monitoring
const int MOISTURE_PIN = A3;     // Soil moisture monitoring
const int PH_SENSOR_PIN = A4;    // Soil pH balance

// Voice Module (DFPlayer Mini) Pins
const int DF_RX = 10;
const int DF_TX = 11;

SoftwareSerial voiceSerial(DF_RX, DF_TX);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  voiceSerial.begin(9600);

  Serial.println("--- SHIVA SURAKSHA SYSTEM STARTING ---");

  // Initializing Voice Module
  if (!myDFPlayer.begin(voiceSerial)) {
    Serial.println("Error: DFPlayer not detected. Check SD Card.");
  } else {
    Serial.println("Voice Guidance System: ONLINE");
    myDFPlayer.volume(25); // Set volume (0-30)
  }

  // Pin Modes
  pinMode(MQ136_GAS_PIN, INPUT);
  pinMode(MOISTURE_PIN, INPUT);
}

void loop() {
  // --- 1. SHUDDHAHARA CHAKSHUVU LOGIC (Food Safety) ---
  int chemicalLevel = analogRead(MQ136_GAS_PIN);
  Serial.print("Food Chemical Level: ");
  Serial.println(chemicalLevel);

  if (chemicalLevel > 450) { // Threshold for toxins/Carbide
    Serial.println("WARNING: Toxic Chemicals Detected!");
    myDFPlayer.play(1); // Track 1: "Harmful chemicals found, do not eat" (Telugu)
    delay(5000);
  }

  // --- 2. KSHETRAJNA MARGADARSHI LOGIC (Organic Mentor) ---
  int moistureStatus = analogRead(MOISTURE_PIN);
  int phStatus = analogRead(PH_SENSOR_PIN);

  // Check for Soil Dryness
  if (moistureStatus < 300) {
    Serial.println("Status: Soil is dry. Need Organic Mulching.");
    myDFPlayer.play(2); // Track 2: "Soil is dry, use natural mulch" (Telugu)
    delay(5000);
  }

  // Check for Soil Acidity (pH)
  if (phStatus < 400) {
    Serial.println("Status: Low Soil Fertility.");
    myDFPlayer.play(3); // Track 3: "Apply Jeevamrutham to restore soil" (Telugu)
    delay(5000);
  }

  delay(3000); // Wait 3 seconds before next scan
}
