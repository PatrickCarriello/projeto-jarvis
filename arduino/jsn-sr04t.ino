/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

#define PIN_TRIGGER 4
#define PIN_ECHO 5

float medidaCM = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop()
{
  long duracao;
  // Limpa o trigger
  digitalWrite(PIN_TRIGGER, LOW);
  delayMicroseconds(5);
  // Ativa o trigger por 10 microssegundos
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);
  // Lê o echo e retorna o tempo de envio e recebimento da onda de som em microssegundos
  duracao = pulseIn(PIN_ECHO, HIGH);
  // Calcula a distância, velocidade da onda sonora dividida por 2 (ida e volta)
  medidaCM = duracao * 0.034 / 2;

  Serial.print("Medida: ");
  Serial.print(medidaCM);
  Serial.println("cm");

  delay(1000);
}
