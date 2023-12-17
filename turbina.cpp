#include "turbina.hpp"

bool flag = false;

void setupTurbina()
{
    pinMode(TURBINA_PIN, OUTPUT);
}

void turbina()
{
    if (flag == false)
    {
        pinMode(6, OUTPUT);
        digitalWrite(6, LOW);
        delay(100);
        analogWrite(6, 10);
        delay(100);
        analogWrite(6, 74);
        delay(1000);
        analogWrite(6, 100);
        delay(3000);
        analogWrite(6, 200);
        delay(3000);
        flag = true;
    }
}