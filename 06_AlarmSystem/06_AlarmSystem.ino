#include <LiquidCrystal.h>
// LCD подключения: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int buzzer = 7;
int tempPin = A1;
int ldrPin = A2;
bool alarmActive = false;
bool isLightOn = false; // Флаг для отслеживания состояния освещенности
unsigned long previousMillis = 0; // Переменная для отслеживания времени
const long interval = 200; // Интервал для обновления данных (200 мс)
const int lightThreshold = 500; // Порог освещенности, при котором программа будет работать
// Диапазон температур, при которых сигнализация НЕ будет срабатывать
const float minTemp = 16.0;
const float maxTemp = 20.0;  // Установите максимальное значение на 30°C
void setup() {
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);  // Настройка LCD экрана
  delay(200);  // Небольшая задержка на инициализацию LCD
  Serial.begin(9600);  // Инициализация серийного порта
  // Тестирование дисплея
  lcd.print("LCD test...");
  delay(500);  // Быстрая задержка для теста
  lcd.clear();
}
void loop() {
  unsigned long currentMillis = millis();  // Получаем текущее время
  // Чтение уровня освещенности
  int lightLevel = analogRead(ldrPin);
  // Если светло, программа не должна работать
  if (lightLevel > lightThreshold) {
    if (!isLightOn) { // Проверяем, если свет только что включился
      lcd.clear();  // Очищаем дисплей, чтобы не было мигания
      lcd.setCursor(0, 0);
      lcd.print("It's light, OFF!");
      isLightOn = true; // Помечаем, что свет включен
    }
    noTone(buzzer);  // Останавливаем звук, если светло
    alarmActive = false;  // Сбрасываем активность тревоги
    return;  // Выход из функции loop
  }
  // Если свет выключен, проверяем, нужно ли обновить данные
  if (lightLevel <= lightThreshold) {
    if (isLightOn) { // Если только что стало темно, очищаем экран
      lcd.clear();
      isLightOn = false; // Сбрасываем флаг, что свет был включен
    }
    // Если прошло достаточно времени, обновляем данные
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      // Чтение температуры
      float temp = analogRead(tempPin) * (5.0 / 1023.0); // TMP36: напряжение
      temp = (temp - 0.5) * 100; // Конвертация в Цельсии
      // Дополнительная информация для серийного монитора
      Serial.print("Temp: ");
      Serial.print(temp);
      Serial.print(" C  Light: ");
      Serial.println(lightLevel);
      // Обновление LCD
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temp, 1);
      lcd.print((char)223); // Символ градуса
      lcd.print("C   ");
      lcd.setCursor(0, 1);
      lcd.print("Light: ");
      lcd.print(lightLevel);
      // Если температура меньше 16°C или больше 30°C, активируем сигнализацию
      if (temp < minTemp || temp > maxTemp) {
        if (!alarmActive) {
          alarmSignal(); // Запускаем сигнал тревоги
          alarmActive = true;
          playBackgroundMusic(); // Воспроизводим фоновую музыку
        }
      } else {
        // Если температура в диапазоне от 16°C до 30°C, сигнализация не срабатывает
        if (alarmActive) {
          noTone(buzzer);  // Останавливаем звук
          alarmActive = false;
        }
      }
    }
  }
}
// Функция для проигрывания фоновой музыки
void playBackgroundMusic() {
  tone(buzzer, 440, 500); // A4
  delay(500);
  tone(buzzer, 494, 500); // B4
  delay(500);
  tone(buzzer, 523, 500); // C5
  delay(500);
  noTone(buzzer);
}
// Функция для активации сигнализации
void alarmSignal() {
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 1000, 200);
    delay(250);
  }
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 1000, 500);
    delay(600);
  }
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 1000, 200);
    delay(250);
  }
}
