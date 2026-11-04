// Первый светофор (3 цвета)
const int red1 = 13;
const int yellow1 = 12;
const int green1 = 11;
// Второй светофор (2 цвета)
const int red2 = 7;
const int green2 = 6;
void setup() {
pinMode(red1, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(green2, OUTPUT);
}
void loop() {
// Первый светофор – красный, второй – зеленый
digitalWrite(red1, HIGH);
digitalWrite(yellow1, LOW);
digitalWrite(green1, LOW);
digitalWrite(red2, LOW);
digitalWrite(green2, HIGH);
delay(5000); // 5 сек
// Первый светофор – желтый перед сменой
digitalWrite(yellow1, HIGH);
delay(1000); // 1 сек
// Первый светофор – зеленый, второй – красный
digitalWrite(red1, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(green2, LOW);
delay(5000); // 5 сек
// Зеленый мигает 3 раза перед сменой
for (int i = 0; i < 3; i++) {
digitalWrite(green1, LOW);
delay(500); // Полсекунды выключен
digitalWrite(green1, HIGH);
delay(500); // Полсекунды включен
}
// Первый светофор – желтый перед сменой
digitalWrite(green1, LOW);
digitalWrite(yellow1, HIGH);
delay(1000); // 1 сек
}
