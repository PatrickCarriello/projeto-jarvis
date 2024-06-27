/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Pins 74HC595
#define PIN_DATA 3
#define PIN_CLOCK 4
#define PIN_LATCH 5

int act = 1;

void setup()
{
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 32; i++)
  {
    for (int f = 0; f < 32; f++)
    {
      if (f <= i)
      {
        digitalWrite(PIN_DATA, act);
      }
      else
      {
        digitalWrite(PIN_DATA, !act);
      }
      digitalWrite(PIN_CLOCK, HIGH);
      digitalWrite(PIN_CLOCK, LOW);
    }
    delay(100);

    digitalWrite(PIN_LATCH, HIGH);
    digitalWrite(PIN_LATCH, LOW);
  }

  act = !act;
}
