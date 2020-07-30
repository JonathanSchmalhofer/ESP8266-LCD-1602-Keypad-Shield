#include <LiquidCrystal.h>
LiquidCrystal lcd(D5, D6, D0, D1, D2, D3);

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.begin(16, 2); // cols, rows
  lcd.clear();
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  DisplayKeypress(sensorValue);
  delay(1);        // delay in between reads for stability
}

void DisplayKeypress(int sensorValue) {
  lcd.setCursor(0, 0);
  lcd.print("Button Pressed:");
  lcd.setCursor(0, 1);
  if (sensorValue <= 80) {
    lcd.print("Right           ");
  } else if(sensorValue > 80 && sensorValue <= 250) {
    lcd.print("Up              ");
  } else if(sensorValue > 250 && sensorValue <= 430) {
    lcd.print("Down            ");
  } else if(sensorValue > 430 && sensorValue <= 630) {
    lcd.print("Left            ");
  } else if(sensorValue > 630 && sensorValue <= 880) {
    lcd.print("Select          ");
  } else {
    lcd.print("                ");
  }
}
