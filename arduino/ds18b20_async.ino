#include <OneWire.h>
#include <DallasTemperature.h>
#include <NonBlockingDallas.h>

#define temperaturas 4
#define TEMPO_TEMPERATURAS 1500

OneWire oneWire(temperaturas);
DallasTemperature dallasTemp(&oneWire);
NonBlockingDallas sensoresTemp(&dallasTemp);
DeviceAddress endereco;
float temperatura = 0;
int totalSensoresTemperatura = 0;

void setup() {
  Serial.begin(9600);

  // Inicia os sensores de temperatura
  sensoresTemp.begin(NonBlockingDallas::resolution_12, TEMPO_TEMPERATURAS);
  totalSensoresTemperatura = sensoresTemp.getSensorsCount();
  // Callbacks
  sensoresTemp.onIntervalElapsed(handleIntervalElapsed);
  sensoresTemp.onTemperatureChange(handleTemperatureChange);
  sensoresTemp.onDeviceDisconnected(handleDeviceDisconnected);
  // Call the following function whenever you want to request a new temperature reading without waiting for TIME_INTERVAL to elapse
  sensoresTemp.requestTemperature();
}

void loop() {
  // Atualiza os sensores de temperatura
  sensoresTemp.update();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C, Endereço: ");
  Serial.println(sensoresTemp.getAddressString(0));
  delay(500);
}

// Invoked at every VALID sensor reading.
void handleIntervalElapsed(int deviceIndex, int32_t temperatureRAW)
{
  //
}

// Invoked ONLY when the temperature changes between two VALID sensor readings.
void handleTemperatureChange(int deviceIndex, int32_t temperatureRAW)
{
  temperatura = sensoresTemp.rawToCelsius(temperatureRAW);
}

// Invoked when the sensor reading fails
void handleDeviceDisconnected(int deviceIndex)
{
  //
}
