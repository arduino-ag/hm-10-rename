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
    if (Serial.available())
    {
        recvChar = Serial.read();
        Serial1.write(recvChar);
    }
}