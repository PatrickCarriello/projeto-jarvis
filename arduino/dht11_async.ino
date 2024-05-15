/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

#include "DHT_Async.h"

#define PIN_DHT11 3

DHT_Async dht11a(PIN_DHT11, DHT_TYPE_11);
float temperatura = 0;
float humidade = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Atualiza o sensor DHT
  lerDHT();

  // Outras execuções

  delay(1);
}

// Efetua a leitura do sensor
void lerDHT()
{
  static unsigned long tempo = millis();

  // Mede a cada 4 segundos
  if (millis() - tempo > 4000ul)
  {
    unsigned long tempoInicial = millis();
    if (dht11a.measure(&temperatura, &humidade))
    {
      tempo = millis();
      Serial.print("Temperatura: ");
      Serial.print(temperatura);
      Serial.print("°C, Humidade: ");
      Serial.print(humidade);
      Serial.print("%, Tempo leitura: ");
      Serial.println(millis() - tempoInicial);
    }
  }
}
