// infos https://forum.ardumower.de/threads/configure-the-hm-10-bluetooth-4-0-module-using-an-arduino-due-board.23860/
// TL;DR
// HM10 -> Arduino MEGA
// RTX -> Pin 18
// TXD -> Pin 19
// GND -> GND
// VCC -> 3.3V
//
// Commands over Serial
// AT+NAMEname -> Sets the name of the device to 'name'
// AT+NAME -> Returns the name of the device
// AT -< Returns OK if everything is fine

#include <HardwareSerial.h>

void setup()
{
    Serial.begin(115200); // 115200 to console
    delay(500);
    Serial1.begin(9600); // 9600 to HM10
    delay(500);
}

void loop()
{

    char recvChar;
    if (Serial1.available())
    {
        recvChar = Serial1.read();
        Serial.print(recvChar);
    }
    else if (Serial.available())
    {
        recvChar = Serial.read();
        Serial1.write(recvChar);
    }
}