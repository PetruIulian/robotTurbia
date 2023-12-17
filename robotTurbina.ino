#include "motor.hpp"
#include "turbina.hpp"
#include "senzori.hpp"
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    //setupMotor();
    //calibrareSenzori();
    setupTurbina();
    turbina();
}

void loop()
{
    //citireSenzori();
    //go(100, 100);
}
