#include <NewPing.h>      // Библиотека для HC-SR 04

#define TRIGGER_PIN 8     // Пин trig ультразвукового сонара
#define ECHO_PIN 9        // Пин echo ультразвукового сонара
#define MAX_DISTANCE 400  // Придельная дальность работы ультразвукового сонара

#define SPEED_L 5         // Скорость вращения левого мотора
#define DIR_L 4           // Направление вращения левого мотора
#define SPEED_R 6         // Скорость вращения правого мотора
#define DIR_R 7           // Направление вращения правого мотора

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int SonarDist;

void setup() {
  for (int i = 4; i < 8; i++) {     
    pinMode(i, OUTPUT);
  }
}

void loop() {
  SonarDist = sonar.ping_cm();
  motor-rotation();
}

void motor-rotation () {
  if (SonarDist > 20 ){
    digitalWrite(DIR_L, LOW);   // устанавливаем направление мотора «M1» в одну сторону
    analogWrite(SPEED_L, 255);  // включаем мотор на максимальной скорости
    digitalWrite(DIR_R, LOW);   // устанавливаем направление мотора «M2» в одну сторону
    analogWrite(SPEED_R, 200);  // включаем второй мотор на максимальной скорости
  } else if ( SonarDist < 21) {
    digitalWrite(DIR_L, HIGH);  // устанавливаем направление мотора «M1» в другую сторону
    digitalWrite(DIR_R, LOW);   // устанавливаем направление мотора «M2» в одну сторону
    analogWrite(SPEED_R, 255);  // включаем второй мотор на максимальной скорости
  } else {
    analogWrite(SPEED_L, 0);    // выключаем первый мотор
    analogWrite(SPEED_R, 0);    // выключаем второй мотор 
  }
}
