/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

#include <DHT11.h>

#define PIN_DHT11 3

DHT11 dht11a(PIN_DHT11);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned long tempo = millis();
  int temperatura = dht11a.readTemperature();
  unsigned long tempoTemperatura = millis() - tempo;
  int humidade = dht11a.readHumidity();
  unsigned long tempoHumidade = millis() - tempoTemperatura - tempo;

  Serial.print("Tempo temperatura: ");
  Serial.print(tempoTemperatura);
  Serial.print(", Tempo humidade: ");
  Serial.print(tempoHumidade);
  Serial.print(", Tempo total: ");
  Serial.println(millis() - tempo);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C, Humidade: ");
  Serial.print(humidade);
  Serial.println("%");
  // delay(2000);
}
