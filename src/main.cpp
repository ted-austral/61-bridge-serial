/*
 *  main.cpp
 *      61-bridge-serial
 */

#include <Arduino.h>


static void
updateSerial(void)
{
    while(Serial.available())
        Serial2.write(Serial.read()); // Forward what Serial received to Software Serial Port
    while(Serial2.available())
        Serial.write(Serial2.read()); // Forward what Software Serial received to Serial Port
}

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    Serial2.begin(SERIAL_BAUD,SERIAL_8N1,RX2,TX2);
    delay(1000);
    Serial.println(__FUNCTION__);
}

void
loop(void)
{
    updateSerial();
}


