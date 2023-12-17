#ifndef MOTOR_HPP
#define MOTOR_HPP

#define MOTOR2_PIN1 3 // motor stanga
#define MOTOR2_PIN2 10 // motor stanga
#define MOTOR1_PIN1 5 // motor dreapta
#define MOTOR1_PIN2 9
#include <Arduino.h>

void setupMotor();
void go(int speedLeft, int speedRight);

#endif