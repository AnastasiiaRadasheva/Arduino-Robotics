const int potPin = A0; // Potentsiomeeter ühendatud A0 külge
int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // LEDid ühendatud pin-koodidesse
const int ledCount = sizeof(leds) / sizeof(leds[0]);
void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}
void loop() {
  int potValue = analogRead(potPin); // Loeme potentsiomeetri väärtuse
  int mode = map(potValue, 0, 1023, 0, 5); // 5 režiimi: 0–4
  mode = constrain(mode, 0, 4); // Veendume, et väärtus oleks vahemikus 0 kuni 4
  Serial.print("Valitud režiim: ");
  Serial.println(mode);
  switch (mode) {
    case 0: allBlink(); break;
    case 1: oneByOne(); break;
    case 2: reverseBlink(); break;
    case 3: candleEffect(); break;
    case 4: wave(); break;
  }
}
// Kõik LED-id vilguvad korraga
void allBlink() {
  setAll(HIGH);
  delay(300);
  setAll(LOW);
  delay(300);
}
// LED-id vilguvad järjest
void oneByOne() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }
}
// LED-id vilguvad tagurpidi järjest
void reverseBlink() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(150);
    digitalWrite(leds[i], LOW);
  }
}
// Küünlaefekt (juhuslik vilkumine)
void candleEffect() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(random(50, 120));
    digitalWrite(leds[i], LOW);
    delay(random(30, 100));
  }
}
// "Laine" efekt
void wave() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
  }
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
    delay(100);
  }
}
// Kõik LED-id korraga sisse või välja
void setAll(int state) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], state);
  }
}
