#include <LiquidCrystal.h>
#define BULB_PIN 4 
LiquidCrystal lcd(3, 10, 5, 6, 7, 8);
int buzz = 13;
int led1 = 12;
int led2 = 9;
int led3 = 1;
const int ldr_sensor = A1;
float soil = A0;
int temp = A2;
bool buzzerEnabled = true;  // Flag to control buzzer state

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
    pinMode(A2, INPUT);
    pinMode(buzz, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(ldr_sensor, INPUT);
    pinMode(BULB_PIN, OUTPUT);
    digitalWrite(BULB_PIN, LOW);
}
 
void loop()
{
    //Photoresistor Sensor Calibration
    int tempval = analogRead(temp);
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(tempval);
    
    int ldr_sensor_value = analogRead(ldr_sensor);
    if(ldr_sensor_value >= 250)
    {
        digitalWrite(led1, HIGH);
        if (buzzerEnabled) digitalWrite(buzz, HIGH);
    }
    else if(ldr_sensor_value <= 249)
    {
        digitalWrite(led2, HIGH);
        if (buzzerEnabled) digitalWrite(buzz, LOW);  
    }
    else {
        lcd.setCursor(0, 0);
        lcd.print("");
    }
  
    //Soil Moisture Sensor Calibration
    int soilval = analogRead(soil);
    lcd.setCursor(0, 1);
    lcd.print("Level:");
    lcd.print(soilval);
  
    //Soil Moisture levels are low
    if (soilval <= 525) 
    {
        if (buzzerEnabled) digitalWrite(buzz, HIGH);
        digitalWrite(12, HIGH); // red led glows
        digitalWrite(9, LOW);   // green led off
        digitalWrite(1, LOW);   //blue led off
    }
    //Soil moisture levels are normal
    else if (soilval > 525 && soilval <= 700) 
    {
        if (buzzerEnabled) digitalWrite(buzz, LOW);
        digitalWrite(12, LOW);  //red led off
        digitalWrite(1, LOW);   //blue led off
        digitalWrite(9, HIGH);  //green led on
    }
    // Soil moisture levels are high
    else if (soilval >= 701 && soilval <= 876) 
    {
        if (buzzerEnabled) digitalWrite(buzz, HIGH);
        digitalWrite(1, HIGH);  //blue led on
        digitalWrite(9, LOW);   // green led off
        digitalWrite(12, LOW);  //red led off
    }
    else {
        lcd.setCursor(0, 0);
        lcd.print("");
    }
  
    //Bluetooth Module Calibration
    if (Serial.available()) {
        String message = Serial.readString();
        message.trim();  // Remove any leading/trailing whitespace
        
        // Check the received message and control the bulb and buzzer accordingly
        if (message.equalsIgnoreCase("ON")) {
            digitalWrite(BULB_PIN, HIGH);
            Serial.println("Command received: ON");
            Serial.println("Bulb status: ON");
        } 
        else if (message.equalsIgnoreCase("OFF")) {
            digitalWrite(BULB_PIN, LOW);
            Serial.println("Command received: OFF");
            Serial.println("Bulb status: OFF");
        }
        else if (message == "1") {
            buzzerEnabled = true;
            Serial.println("Command received: 1");
            Serial.println("Buzzer enabled");
        }
        else if (message == "0") {
            buzzerEnabled = false;
            digitalWrite(buzz, LOW);  // Turn off the buzzer immediately
            Serial.println("Command received: 0");
            Serial.println("Buzzer disabled");
        }
        else {
            Serial.println("Invalid command. Use 'ON', 'OFF', '0', or '1'");
        }
    }
  
    // Periodic status check
    static unsigned long lastCheck = 0;
    if (millis() - lastCheck >= 5000) {  // Check every 5 seconds
        lastCheck = millis();
        Serial.print("Bulb status: ");
        Serial.println(digitalRead(BULB_PIN) == HIGH ? "ON" : "OFF");
        Serial.print("Buzzer status: ");
        Serial.println(buzzerEnabled ? "Enabled" : "Disabled");
    }
}