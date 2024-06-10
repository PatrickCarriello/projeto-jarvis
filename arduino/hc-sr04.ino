/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

#include <Ultrasonic.h>

#define PIN_TRIGGER 4
#define PIN_ECHO 5

float medidaCM = 0;
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  long microsec = ultrasonic.timing();
  medidaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print("Medida: ");
  Serial.print(medidaCM);
  Serial.println("cm");

  delay(1000);
}
