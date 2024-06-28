/*
  Autor: Patrick Carriello
  Projeto: Projeto Jarvis
  Detalhes do projeto: https://www.youtube.com/watch?v=L3ky2-lCL8s&list=PLDZLfLztiVAkoGCS805bjnNVWhHrbzk_M
*/

// Pins 74HC595
#define PIN_OUT_DATA 3
#define PIN_OUT_CLOCK 4
#define PIN_OUT_LATCH 5

// Pins 74HC165
#define PIN_IN_DATA 8
#define PIN_IN_CLOCK 9
#define PIN_IN_LOAD 10

// Array
bool inArray[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
// Verifica se alguma entrada foi acionada
bool hasCommand = false;

// Variáveis para a medição do tempo
// Tempo inicial
long int initialReadTime = 0;
// Tempo final
long int finalReadTime = 0;

void setup()
{
  pinMode(PIN_OUT_DATA, OUTPUT);
  pinMode(PIN_OUT_CLOCK, OUTPUT);
  pinMode(PIN_OUT_LATCH, OUTPUT);

  pinMode(PIN_IN_DATA, INPUT);
  pinMode(PIN_IN_CLOCK, OUTPUT);
  pinMode(PIN_IN_LOAD, OUTPUT);
}

void loop()
{
  readInputs();
  outCommands();
}

// Verifica se é o momento de ler os dados dos sensores touch
bool timeToReadInputs()
{
  if (initialReadTime == 0)
  {
    initialReadTime = millis();
    return false;
  }

  finalReadTime = millis();

  // Espera 1 segundo para ler os sensores
  if (finalReadTime - initialReadTime >= 1000)
  {
    initialReadTime = 0;
    return true;
  }

  return false;
}

// Lê os sensores touch (entradas)
void readInputs()
{
  digitalWrite(PIN_IN_LOAD, HIGH);
  for (int i = 0; i < 32; i++)
  {
    int input = digitalRead(PIN_IN_DATA);
    if (input == 1)
    {
      if (timeToReadInputs())
      {
        inArray[i] = !inArray[i];
        hasCommand = true;
      }
    }
    clockIN();
  }
  digitalWrite(PIN_IN_LOAD, LOW);
}

// Envia os comandos para as saídas
void outCommands()
{
  if (hasCommand)
  {
    for (int i = 0; i < 32; i++)
    {
      digitalWrite(PIN_OUT_DATA, inArray[i]);
      clockOUT();
    }

    digitalWrite(PIN_OUT_LATCH, HIGH);
    digitalWrite(PIN_OUT_LATCH, LOW);
    hasCommand = false;
  }
}

// Clock de entrada
void clockIN()
{
  digitalWrite(PIN_IN_CLOCK, HIGH);
  digitalWrite(PIN_IN_CLOCK, LOW);
}

// Clock de saída
void clockOUT()
{
  digitalWrite(PIN_OUT_CLOCK, HIGH);
  digitalWrite(PIN_OUT_CLOCK, LOW);
}
