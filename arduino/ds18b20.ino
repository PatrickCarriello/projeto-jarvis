#include <OneWire.h>
#include <DallasTemperature.h>

#define temperaturas 4

OneWire oneWire(temperaturas);
DallasTemperature sensoresTemp(&oneWire);
DeviceAddress endereco;
int totalSensoresTemperatura = 0;

void setup() {
  Serial.begin(9600);

  // Inicia os sensores de temperatura
  sensoresTemp.begin();
  // Pega a quantidade de sensores conectados
  totalSensoresTemperatura = sensoresTemp.getDeviceCount();
}

void loop() {
  unsigned long tempo = millis();
  // Sensores de temperatura
  sensoresTemp.requestTemperatures();
  long temperatura = sensoresTemp.getTempCByIndex(0);

  Serial.print("Tempo temperatura: ");
  Serial.print(millis() - tempo);
  Serial.print(", Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C, Endereço: ");
  Serial.println(sensoresTemp.getAddress(endereco, 0));
}
