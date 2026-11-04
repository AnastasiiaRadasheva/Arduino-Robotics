const int potensiometr = 1;
int fototakisti = 0;   
int lightLevel, high = 0, low = 1023;
const int RED1 = 10;
const int BLUE1 = 9;
const int GREEN1 = 8;
int sensorValue = constrain(sensorValue, 10, 150);
int Value_new;
void setup()
{
  pinMode(RED1, OUTPUT);
  pinMode(BLUE1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
}
void loop()
{
  digitalWrite(RED1, LOW);
  digitalWrite(BLUE1, LOW);
  digitalWrite(GREEN1, LOW);
  lightLevel = analogRead(fototakisti);
  manualTune();
  Value_new = analogRead(potensiometr);
  Value_new = map(Value_new,0,1023,0,3);
  if (Value_new == 2)
  {
    BLUE();
  }
  else if (Value_new == 1)
  {
    RED();
  }
  else if (Value_new == 3)
  {
    GREEN();
  }
  else
  {
    digitalWrite(RED1, LOW);
    digitalWrite(BLUE1, LOW); 
    digitalWrite(GREEN1, LOW);
  }
}
void manualTune()
{
  lightLevel = map(lightLevel, 300, 800, 0, 255); 
  lightLevel = constrain(lightLevel, 0, 255);
} 
void GREEN()
{
  digitalWrite(GREEN1, lightLevel);
}
void RED()
{
  digitalWrite(RED1, lightLevel);
}
void BLUE()
{
  digitalWrite(BLUE1, lightLevel); 
}
