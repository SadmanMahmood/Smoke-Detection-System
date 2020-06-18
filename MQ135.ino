#include <LiquidCrystal.h> // Include the LCD Library
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

int sensorPin = A0; //Define the Pin that the A0 of MQ135 is connected to
int sensorValue = 0; //Create a variable to store the variable in
int led = 13; //Define the Pin that the LED is connected to

void setup() {
  // Code here will run once
  lcd.begin(16,2);   // begin the communication between the LCD and Arduino
  Serial.begin(9600); // begin the Serial Coummunication between the Arduino and Serial Monitor
  pinMode(led, OUTPUT); // Define the LED is Input or Output
}

void loop() {
  // Code here will run repeatedly
  delay(2000);
  sensorValue = analogRead(sensorPin); // Reading the Value from the sensor
  if (sensorValue < 305){                            //
  lcd.setCursor(0,0);                                // 
  lcd.print("      GAS       ");                     //
  lcd.setCursor(0,1);                                //
  lcd.print("  Not Detected  ");                     // 
  digitalWrite(led, LOW);                            // 
  }                                                  //   Printing on the LCD monitor
  if (sensorValue > 305){                            // 
  lcd.setCursor(0,0);                                //
  lcd.print("      GAS       ");                     //
  lcd.setCursor(0,1);                                //
  lcd.print("    Detected    ");                     //
  digitalWrite(led, HIGH);                           //
  }                                                  //
  Serial.print("Air Quality = "); 
  Serial.print(sensorValue);

  Serial.print("*PPM");
  Serial.println();
  delay(1000);
}
