#include <Servo.h>
#include <LiquidCrystal.h>
// LCD ühendused (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
// Ultraheliandur 1 - SAABUMINE
const int trigPin1 = A3;
const int echoPin1 = A2;
// Ultraheliandur 2 - LAHKUMINE
const int trigPin2 = A1;
const int echoPin2 = A0;
// RGB LED
const int redPin = 2;
const int greenPin = 0;
const int bluePin = 1;
// Servo
Servo barrierServo;
const int servoPin = 10;
// Parkimiskohtade arvestus
const int maxSpots = 5;
int occupiedSpots = 0;
// Kauguse lävi (cm)
const int detectDistance = 20;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Systeem kaivitub");
  // Ultraheli pinid
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  // RGB LED
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Servo
  barrierServo.attach(servoPin);
  barrierServo.write(0); // Tõkkepuu suletud
  delay(2000);
  lcd.clear();
}
void loop() {
  long distance1 = getDistance(trigPin1, echoPin1);
  long distance2 = getDistance(trigPin2, echoPin2);
  // SAABUMINE
  if (distance1 < detectDistance) {
    if (occupiedSpots < maxSpots) {
      openBarrier();
      occupiedSpots++;
      delay(3000); // aeg autol sisenemiseks
      closeBarrier();
    } else {
      displayFull();
    }
  }
  // LAHKUMINE
   if (distance2 < detectDistance && occupiedSpots > 0) {
    occupiedSpots--;
    delay(3000); // aeg autol väljumiseks
  }
  displayStatus();
  delay(1000);
}
// --- Funktsioonid ---
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
void openBarrier() {
  barrierServo.write(90); // üles
  setRGB(0, 255, 0);       // roheline
}
void closeBarrier() {
  barrierServo.write(0);  // alla
  setRGB(0, 0, 255);       // sinine
}
void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
void displayStatus() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vabu kohti: ");
  lcd.print(maxSpots - occupiedSpots);
  if (occupiedSpots == maxSpots) {
    setRGB(255, 0, 0); // punane - täis
  }
}
void displayFull() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Parkla on tais!");
  setRGB(255, 0, 0);
  delay(3000);
}
