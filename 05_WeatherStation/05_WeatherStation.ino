#include <LiquidCrystal.h>
// LCD ühendused: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Andurite pinid
const int sensorPinTemp = A0;
const int sensorPinValgus = A1;
// Kohandatud ikoonid (päike, pilv, vihm, lumi, süda)
byte sun[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};
byte cloud[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b10101,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};
byte rain[8] = {
  0b00000,
  0b01110,
  0b10101,
  0b11111,
  0b11111,
  0b00100,
  0b01010,
  0b00100
};
byte snow[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};
// Aeg-ajalt reklaamtekst
const char* reklaamTekst = "Hello! :)";
// Muutujad uuenduse jaoks
unsigned long eelmiseAeg = 0;
const long intervall = 5000; // 5 sekundi tagant uuendus
int reklaamiLoendur = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Kohandatud ikoonid
  lcd.createChar(0, sun);
  lcd.createChar(1, cloud);
  lcd.createChar(2, rain);
  lcd.createChar(3, snow);
  lcd.createChar(4, heart);
  // Alguskuva
  lcd.setCursor(0, 0);
  lcd.print("Ilmajaam:");
  lcd.setCursor(0, 1);
  lcd.print("PaiksePesa");
  delay(3000);
  lcd.clear();
}
void loop() {
  unsigned long praeguneAeg = millis();
  // Värskenda iga 5 sekundi tagant
  if (praeguneAeg - eelmiseAeg >= intervall) {
    eelmiseAeg = praeguneAeg;
    int sensorTempVal = analogRead(sensorPinTemp);
    int sensorValgusVal = analogRead(sensorPinValgus);
    // Temperatuuri arvutus TMP36 sensorilt
    float voltage = sensorTempVal * 5.0 / 1024.0;
    float temperature = (voltage - 0.5) * 100;
    // Valguse hindamine (skaalame lihtsamaks)
    int ValgusVal = sensorValgusVal / 4;
    // Seriaalmonitori test
    Serial.print("Temp (C): ");
    Serial.println(temperature);
    Serial.print("Valgus: ");
    Serial.println(sensorValgusVal);
    lcd.clear();
    // Kuvame ilmastiku kirjelduse ja ikooni
    lcd.setCursor(0, 0);
    if (temperature < 0) {
      lcd.print("Voib tulla lund");
      lcd.setCursor(15, 0);
      lcd.write(byte(3)); // lumi
    }
    else if (temperature >= 0 && temperature < 10 && ValgusVal < 100) {
      lcd.print("Pilvine ja jahe");
      lcd.setCursor(15, 0);
      lcd.write(byte(1)); // pilv
    }
    else if (temperature >= 0 && temperature < 10 && ValgusVal >= 100) {
      lcd.print("Vihmane ilm");
      lcd.setCursor(15, 0);
      lcd.write(byte(2)); // vihm
    }
    else if (temperature >= 10 && temperature < 20 && ValgusVal < 100) {
      lcd.print("Pilvine hommik");
      lcd.setCursor(15, 0);
      lcd.write(byte(1)); // pilv
    }
    else if (temperature >= 10 && ValgusVal >= 100) {
      lcd.print("Paike paistab!");
      lcd.setCursor(15, 0);
      lcd.write(byte(0)); // paike
    }
    else {
      lcd.print("Ilm muutlik");
      lcd.setCursor(15, 0);
      lcd.write(byte(1)); // pilv (vaikimisi)
    }
    // Kuvame temperatuuri allreal
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature, 0);
    lcd.print((char)223);
    lcd.print("C");
    // Aeg-ajalt näitame reklaami (iga 4. kord)
    reklaamiLoendur++;
    if (reklaamiLoendur >= 4) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(reklaamTekst);
      lcd.setCursor(15, 1);
      lcd.write(byte(4)); // süda
      delay(3000);
      reklaamiLoendur = 0;
    }
  }
}
