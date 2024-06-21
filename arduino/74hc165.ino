/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Pins 74HC165
#define PIN_DATA 3
#define PIN_CLOCK 4
#define PIN_LOAD 5

// Array
bool inArray[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_DATA, INPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_LOAD, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_LOAD, HIGH);
  for (int i = 0; i < 32; i++)
  {
    int inData = digitalRead(PIN_DATA);
    if (inData != inArray[i])
    {
      Serial.print("ID ");
      Serial.print(i + 1);
      Serial.print(" set to ");
      Serial.println(inData);
    }
    inArray[i] = inData;
    // Clock
    digitalWrite(PIN_CLOCK, HIGH);
    digitalWrite(PIN_CLOCK, LOW);
  }
  digitalWrite(PIN_LOAD, LOW);
}
