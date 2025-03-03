# Smart-Agriculture-Monitoring-System

## Overview

This project implements a smart agriculture monitoring system using an Arduino UNO, various sensors, and Bluetooth communication. It allows for real-time monitoring of temperature, soil moisture, and light levels, as well as manual control of a bulb and buzzer via Bluetooth. The system displays sensor readings on an LCD and provides status updates through the serial monitor.

## Features

- **Real-time Monitoring:**
    - Temperature reading displayed on the LCD.
    - Soil moisture level displayed on the LCD.
    - Light level monitoring using a photoresistor.
- **Visual Feedback:**
    - LEDs indicate different soil moisture levels (low, normal, high).
    - LEDs indicate light level (day/night).
- **Audible Alerts:**
    - Buzzer sounds when soil moisture is too low or too high, and during daytime.
- **Manual Control via Bluetooth:**
    - Control a connected bulb (ON/OFF).
    - Enable/disable the buzzer.
- **Status Updates:**
    - Periodic status updates sent to the serial monitor (bulb and buzzer status).

## Hardware Components

- Arduino UNO
- LCD Display (16x2)
- Photoresistor (LDR)
- Soil Moisture Sensor
- Temperature Sensor (Analog)
- LEDs (Red, Green, Blue)
- Buzzer
- Bulb
- Bluetooth Module (e.g., HC-05)
- Breadboards
- Jumper Wires

## Circuit Diagram

![image](https://github.com/user-attachments/assets/fa2cfa48-8f9d-42be-ad4a-75ba827469d1)
![image](https://github.com/user-attachments/assets/0f3338a9-ebe8-4dfb-82aa-67b45c6c81ec)
  
**Note:** Please refer to the provided circuit diagram for detailed wiring connections.

## Software Components

- Arduino IDE

## Libraries Used

- LiquidCrystal.h (Included with Arduino IDE)

## Setup

1. **Hardware Setup:**
   - Connect the components as per the circuit diagram.
   - Ensure proper connections for the Bluetooth module.

2. **Software Setup:**
   - Install the Arduino IDE if you haven't already.
   - Open the Arduino IDE and create a new sketch.
   - Copy and paste the provided code into the sketch.
   - Select the correct board and port in the Arduino IDE.
   - Upload the code to your Arduino UNO.

3. **Bluetooth Setup:**
   - Pair your smartphone or computer with the Bluetooth module.
   - Use a serial monitor application (e.g., Arduino Serial Monitor, Serial Bluetooth Terminal) to send commands.

## Usage

1. **Monitoring:**
   - The LCD will display real-time temperature and soil moisture readings.
   - The LEDs will indicate the soil moisture and light levels.
   - The buzzer will sound based on the soil moisture and light conditions.

2. **Bluetooth Control:**
   - Open the serial monitor application and connect to the Bluetooth module.
   - Send the following commands to control the bulb and buzzer:
     - `ON`: Turn the bulb ON.
     - `OFF`: Turn the bulb OFF.
     - `1`: Enable the buzzer.
     - `0`: Disable the buzzer.

3. **Status Updates:**
   - The system will periodically send status updates to the serial monitor (bulb and buzzer status) every 5 seconds.

## Code Explanation

- The code initializes the LCD, serial communication, and pin modes.
- It continuously reads sensor values and updates the LCD and LEDs accordingly.
- It checks for incoming Bluetooth commands and controls the bulb and buzzer based on the received commands.
- It sends periodic status updates to the serial monitor.

## Troubleshooting

- **LCD not displaying:** Check the wiring and ensure the LCD library is correctly included.
- **Bluetooth not connecting:** Verify the Bluetooth module connections and pairing process.
- **Sensor readings incorrect:** Calibrate the sensors and check the wiring.
- **Buzzer not working:** Check the buzzer connections and ensure the buzzer is enabled.
- **Bulb not turning on/off:** Verify the bulb connections and Bluetooth commands.

## Future Enhancements

- Implement a web interface for remote monitoring and control.
- Add more sensors (e.g., humidity, pH).
- Implement automated irrigation and lighting control.
- Integrate with cloud platforms for data logging and analysis.

## Author

Lewis Munene Muthee

## License

This project is licensed under the [MIT License](LICENSE).

---
