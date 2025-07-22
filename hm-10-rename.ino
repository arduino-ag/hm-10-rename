// infos https://forum.ardumower.de/threads/configure-the-hm-10-bluetooth-4-0-module-using-an-arduino-due-board.23860/
// TL;DR
// HM10 -> Arduino MEGA
// RTX -> Pin 51
// TXD -> Pin 50
// GND -> GND
// VCC -> 3.3V
//
// Commands over Serial
// AT+NAMEname -> Sets the name of the device to 'name'
// AT+NAME -> Returns the name of the device
// AT -> Returns OK if everything is fine

#include <HardwareSerial.h>
#include <SoftwareSerial.h>

const byte rx = 50;
const byte tx = 51;

SoftwareSerial software_serial(rx, tx);

void setup()
{
    Serial.begin(9600); // 115200 to console
    delay(500);
    software_serial.begin(9600); // 9600 to HM10
    delay(500);
}

void loop()
{

    char recvChar;
    if (software_serial.available())
    {
        recvChar = software_serial.read();
        Serial.print(recvChar);
    }
    
    if (Serial.available())
    {
        recvChar = Serial.read();
        software_serial.write(recvChar);
    }
}
