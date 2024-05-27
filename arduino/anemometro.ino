/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Anemômetro
#define PIN_ANEMOMETRO 3

const float pi = 3.14159265;
int periodoMedicaoAnemometro = 5000;
// Raio do anemometro(mm)
int radiusAnemometro = 147;
unsigned int contagemAnemometro = 0;
unsigned int rpmAnemometro = 0;
// Velocidade (m/s)
float velocidadeAnemometroMS = 0;
// Velocidade (km/h)
float velocidadeAnemometroKMH = 0;
long inicioTempoAnemometro = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_ANEMOMETRO, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_ANEMOMETRO), anemometerCount, RISING);
}

void loop()
{
  // Atualiza o anemômetro
  lerAnemometro();

  delay(1);
}

// Lê os dados do anemômetro
void lerAnemometro()
{
  if (inicioTempoAnemometro == 0)
  {
    inicioTempoAnemometro = millis();
    return;
  }

  if (millis() >= inicioTempoAnemometro + periodoMedicaoAnemometro)
  {
    rpmAnemometro = (contagemAnemometro * 60) / (periodoMedicaoAnemometro / 1000);
    velocidadeAnemometroMS = ((4 * pi * radiusAnemometro * rpmAnemometro) / 60) / 1000;
    velocidadeAnemometroKMH = velocidadeAnemometroMS * 3.6;
    Serial.print("Anemômetro: KM/H: ");
    Serial.print(velocidadeAnemometroKMH);
    Serial.print(", M/S: ");
    Serial.print(velocidadeAnemometroMS);
    Serial.print(", RPM: ");
    Serial.println(rpmAnemometro);
    contagemAnemometro = 0;
    inicioTempoAnemometro = 0;
  }
}

// Contador do anemômetro
void anemometerCount()
{
  contagemAnemometro++;
}
