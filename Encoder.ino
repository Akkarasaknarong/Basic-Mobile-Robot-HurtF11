
#define led 25
#include "MOTOR.h"
Motor FL(2, 10, 11, 200, 20, 0);
Motor FR(4, 12, 13, 200, 20, 0);
Motor BL(6, 14, 15, 200, 20, 0);
Motor BR(8, 20, 21, 200, 20, 0);

Motor Gripper(8, 10, 11, 200, 20, 0);

#define led 25

void setup() {
  digitalWrite(led, HIGH);
  Serial.begin(9600);
  // FL.setSpeed(255);
  // FR.setSpeed(255);
  // BL.setSpeed(255);
  // BR.setSpeed(255);
  // hurtttttttttttttttttttt
  

  pinMode(led, OUTPUT);
  for (int i = 1; i < 40; i++) {
    digitalWrite(led, HIGH);
    delay(30);
    digitalWrite(led, LOW);
    delay(30);
  }
  digitalWrite(led, HIGH);
}

void loop() {
  Gripper.setSpeed(100);
  delay(650);
  Gripper.stop();
  delay(1000);
  Gripper.setSpeed(-100);
  delay(240);
  Gripper.stop();
  delay(1000);
}
