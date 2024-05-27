/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Biruta
#define PIN_BIRUTA A0

int direcaoVentoGraus = 0;
String direcaoVento = "-";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float valorBiruta = analogRead(PIN_BIRUTA) * (5.0 / 1023.0);

  if (valorBiruta <= 0.27)
  {
    direcaoVentoGraus = 315;
    direcaoVento = "NO";
  }
  else if (valorBiruta <= 0.32)
  {
    direcaoVentoGraus = 270;
    direcaoVento = "O";
  }
  else if (valorBiruta <= 0.38)
  {
    direcaoVentoGraus = 225;
    direcaoVento = "SO";
  }
  else if (valorBiruta <= 0.45)
  {
    direcaoVentoGraus = 180;
    direcaoVento = "S";
  }
  else if (valorBiruta <= 0.57)
  {
    direcaoVentoGraus = 135;
    direcaoVento = "SE";
  }
  else if (valorBiruta <= 0.75)
  {
    direcaoVentoGraus = 90;
    direcaoVento = "L";
  }
  else if (valorBiruta <= 1.25)
  {
    direcaoVentoGraus = 45;
    direcaoVento = "NE";
  }
  else
  {
    direcaoVentoGraus = 0;
    direcaoVento = "N";
  }

  Serial.print("Biruta: Direção: ");
  Serial.print(direcaoVento);
  Serial.print(", Graus: ");
  Serial.println(direcaoVentoGraus);

  delay(2000);
}
