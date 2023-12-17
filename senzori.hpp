#ifndef SENZORI_HPP
#define SENZORI_HPP

#include <QTRSensors.h>
#include <Arduino.h>

#define NUM_SENSORS 8
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN 2

void calibrareSenzori();
void citireSenzori();

#endif