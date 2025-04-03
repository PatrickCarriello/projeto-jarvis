/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

#define PIN_TRIGGER 4
#define PIN_ECHO 5

float medidaCM = 0;
float medidaCMAntiga = 0;
// Arrays
float arrayMedicoes[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float arrayMedicoesTemp[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// Índice atual
int indexUltrassom = 0;
// Tempo inicial
long int tempoUltrassomInicial = 0;
// Tempo final
long int tempoUltrassomFinal = 0;

// Ordena um array de valores
void ordenaArray(float arr[])
{
  int i, j;
  float temp;
  for (i = 0; i < (20 - 1); ++i)
  {
    for (j = 0; j < 20 - 1 - i; ++j)
    {
      if (arr[j] > arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// Soma as medições do ultrassom
float somaMedicoesUltrassom(float arr[])
{
  int i;
  float soma = 0;
  for (i = 5; i < 15; i++) 
    soma += arr[i];
  return soma / 10;
}

// Verifica se é o momento de ler os dados do sensor ultrassom
bool horaDeLerUltrassom()
{
  if (tempoUltrassomInicial == 0)
  {
    tempoUltrassomInicial = millis();
    return false;
  }

  tempoUltrassomFinal = millis();

  // Espera 300 millissegundos para ler o sensor
  if (tempoUltrassomFinal - tempoUltrassomInicial >= 300)
  {
    tempoUltrassomInicial = 0;
    return true;
  }

  return false;
}

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop()
{
  if (horaDeLerUltrassom())
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
    // medidaCM = duracao * 0.034 / 2;
    arrayMedicoesTemp[indexUltrassom] = duracao * 0.034 / 2;

    ++indexUltrassom;

    if (indexUltrassom == 20)
    {
      int i;
      for (i = 0; i < 20; i++)
      {
        arrayMedicoes[i] = arrayMedicoesTemp[i];
      }
      ordenaArray(arrayMedicoes);
      medidaCM = somaMedicoesUltrassom(arrayMedicoes);
      indexUltrassom = 0;
    }
  }

  if (medidaCM != medidaCMAntiga) {
    Serial.print("Medida: ");
    Serial.print(medidaCM);
    Serial.println("cm");
    medidaCMAntiga = medidaCM;
  }

  delay(1);
}
