/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Pluviômetro
#define PIN_PLUVIOMETRO 3

int contagemPluviometro = 0;

void setup()
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(PIN_PLUVIOMETRO), pluviometerCount, RISING);
}

void loop()
{
  Serial.print("Pluviômetro: ");
  Serial.println(contagemPluviometro * 0.25);

  if (contagemPluviometro > 0)
  {
    // Zera a contagem do pluviômetro
    contagemPluviometro = 0;
  }

  delay(5000);
}

// Contador do pluviômetro
void pluviometerCount()
{
  contagemPluviometro++;
}
