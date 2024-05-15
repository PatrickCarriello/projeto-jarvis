/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Pinos
// Fase 1 da energia elétrica
#define FASE1 2
// Fase 2 da energia elétrica
#define FASE2 3
// Relé de Fase do Jarvis
#define RELE_FASE 4

void setup()
{
  Serial.begin(9600);

  pinMode(RELE_FASE, OUTPUT);
  pinMode(FASE1, INPUT);
  pinMode(FASE2, INPUT);
}

void loop()
{
  // Fase 1
  int valor_fase1 = digitalRead(FASE1);
  String texto_fase1 = "";
  if (valor_fase1 == LOW)
  {
    texto_fase1 = "DESLIGADA";
    // Regra para ligar o relé na fase 2
    digitalWrite(RELE_FASE, HIGH);
  }
  else
  {
    texto_fase1 = "LIGADA";
    // Desliga o relé (mantendo ligada na fase 1)
    digitalWrite(RELE_FASE, LOW);
  }

  // Fase 2
  int valor_fase2 = digitalRead(FASE2);
  String texto_fase2 = "";
  if (valor_fase2 == LOW)
  {
    texto_fase2 = "DESLIGADA";
  }
  else
  {
    texto_fase2 = "LIGADA";
  }

  // Texto enviado para o Serial
  Serial.println("Fase 1: " + texto_fase1 + ", Fase 2: " + texto_fase2);

  // Aguarda meio segundo para recomeçar
  delay(500);
}
