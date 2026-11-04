#include <LiquidCrystal.h>
#include <Servo.h>
// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;
const int sigPin = 10;
const int redPin = 13;
const int greenPin = 8;
const int bluePin = 9;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  servo.attach(7);
  servo.write(0);
  // Настройка пинов RGB светодиода
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Hello! :)");
  lcd.setCursor(0, 1);
  lcd.print("Valmis kasutamiseks");
  delay(4000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Prugikast  ^_^");
  delay(2000);
}
void loop() {
  long duration, distance;
  // Отправка сигнала
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);
  // Получение сигнала
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);
  distance = duration * 0.0343 / 2;
  Serial.println(distance);
  if (distance < 50 && distance > 0) {
    servo.write(90);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kast avatud :)");
    digitalWrite(greenPin, HIGH);  // Зелёный свет
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
  } else {
    servo.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kast suletud :(");
    digitalWrite(redPin, HIGH);   // Красный свет
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  delay(500);
}
