#include <Servo.h>
// Пины
const int tempPin = A0;    // Пин датчика температуры (TMP36)
const int ldrPin = A1;     // Пин фотосопротивления
const int ledPin = 2;      // Пин LED
const int servoPin = 13;    // Пин сервомотора
// Переменные
Servo servo;
int currentAngle = 0;      // Текущий угол серво
int targetAngle = 0;       // Целевой угол серво
void setup() {
  pinMode(ledPin, OUTPUT);
  servo.attach(servoPin);
  servo.write(currentAngle); // Начальная позиция
  Serial.begin(9600);       // Для отладки
}
void loop() {
  // Чтение температуры
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100; // Для TMP36
  // Определение целевого угла
  if (temperature <= 20) {
    targetAngle = 0;   // Окно закрыто
  } else if (temperature >= 30) {
    targetAngle = 130; // Окно открыто
  } else {
    targetAngle = currentAngle; // Не менять угол
  }
  // Плавное перемещение серво
  if (currentAngle != targetAngle) {
    servo.attach(servoPin); // Подключаем серво
    if (currentAngle < targetAngle) {
      currentAngle++; // Увеличиваем угол
      servo.write(currentAngle);
      delay(15); // Задержка для плавности
    } else if (currentAngle > targetAngle) {
      currentAngle--; // Уменьшаем угол
      servo.write(currentAngle);
      delay(15); // Задержка для плавности
    }
    // Если угол достигнут, отключаем серво
    if (currentAngle == targetAngle) {
      delay(100); // Ждём стабилизации
      servo.detach(); // Отключаем серво
    }
  }
  // Чтение фотосопротивления и управление LED
  int lightLevel = analogRead(ldrPin);
  if (lightLevel > 500) { // Если темно
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  // Отладка
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("C, Angle: ");
  Serial.print(currentAngle);
  Serial.print(", Light: ");
  Serial.println(lightLevel);
  delay(100); // Пауза между циклами
}
