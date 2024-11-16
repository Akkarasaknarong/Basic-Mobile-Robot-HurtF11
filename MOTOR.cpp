#include "Arduino.h"
#include "MOTOR.h"
// #include "LowPass.h"

Motor::Motor(int encoderPin, int INA_PIN, int INB_PIN, double kp, double ki, double kd)
  : encoder(encoderPin), _INA_PIN(INA_PIN), _INB_PIN(INB_PIN), _kp(kp), _ki(ki), _kd(kd) {
  pinMode(_INA_PIN, OUTPUT);
  pinMode(_INB_PIN, OUTPUT);
}

void Motor::setSpeed(int speed) {
  if (speed > 0) {
    analogWrite(_INA_PIN, speed);
    digitalWrite(_INB_PIN, 0);
  } else if (speed < 0) {
    digitalWrite(_INA_PIN, 0);
    analogWrite(_INB_PIN, -speed);
  } else {
    digitalWrite(_INA_PIN, 0);
    digitalWrite(_INB_PIN, 0);
  }
}

void Motor::stop() {
  digitalWrite(_INA_PIN, LOW);
  digitalWrite(_INB_PIN, LOW);
}