#include <LiquidCrystal.h>

// define pin assignments
const int RED_LED_PIN = 3;
const int GREEN_LED_PIN = 2;
const int BUZZER_PIN = 4;
const int SENSOR_PIN = A0;
const int SENSOR_THRESHOLD = 400;

// create instances of required objects
LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

void setup() {
  // initialize pin modes
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  // initialize serial communication for debugging
  Serial.begin(9600);

  // initialize LCD screen
  lcd.begin(16, 2);
}

void loop() {
  // read sensor value
  int sensorValue = analogRead(SENSOR_PIN);
  Serial.print(sensorValue);

  // check if sensor value is above the threshold
  if (sensorValue > SENSOR_THRESHOLD) {
    // activate alarm and display alert message
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    tone(BUZZER_PIN, 1000, 10000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("EVACUATE");
    delay(1000);
  } else {
    // turn off alarm and display safe message
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }
}
