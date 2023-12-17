#include "senzori.hpp"
#include "QTRSensors.h"
#include "motor.hpp"

QTRSensorsAnalog qtra((unsigned char[]){A0, A1, A2, A3, A4, A5, A6, A7},
                      NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

float Kp = 8; // 13 fara turbina  // 13 la 380              //8           /20 viteza 370 motoare 5:1      / 12 viteza 350 motoare 10:1     /13 viteza 350
float Kd = 40; // 50 fara turbina// 43 la 380              //55          /56 viteza 370 motoare 5:1      / 29 viteza 350 motoare 10:1    /35 viteza 350
float pozitie_referinta = 35;
float eroare_pozitie;
float eroare_pozitie_anterioara;
float derivativ;
float corectie_viteza; // float corectie_viteza;
float vitezaM1;
float vitezaM2;
float viteza_croaziera = 200;

void calibrareSenzori()
{
    delay(500);
    for (int i = 0; i < 200; i++)
    {
        qtra.calibrate();
    }
    digitalWrite(13, LOW);
    for (int i = 0; i < NUM_SENSORS; i++)
    {
        Serial.print(qtra.calibratedMinimumOn[i]);
        Serial.print(' ');
    }
    Serial.println();

    for (int i = 0; i < NUM_SENSORS; i++)
    {
        Serial.print(qtra.calibratedMaximumOn[i]);
        Serial.print(' ');
    }
    delay(3000);
}

void citireSenzori()
{
    unsigned int pozitie = qtra.readLine(sensorValues) / 100;

    eroare_pozitie = pozitie_referinta - pozitie;

    derivativ = eroare_pozitie - eroare_pozitie_anterioara;

    eroare_pozitie_anterioara = eroare_pozitie;

    corectie_viteza = Kp * eroare_pozitie + Kd * derivativ;

    vitezaM1 = viteza_croaziera + corectie_viteza;

    vitezaM2 = viteza_croaziera - corectie_viteza;

    go(vitezaM1, vitezaM2);

    // for (unsigned char i = 0; i < NUM_SENSORS; i++)
    // {
    //     Serial.print(sensorValues[i]);
    //     Serial.print('\t');
    // }
    Serial.println(pozitie);
}
