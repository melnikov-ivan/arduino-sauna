//include <Nextion.h>
// https://github.com/itead/ITEADLIB_Arduino_Nextion

#include <Adafruit_Si7021.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define temp1pin 9
//#define temp2pin 10

#define level1pin A1
//#define level2pin A2

Adafruit_Si7021 sensor = Adafruit_Si7021();

OneWire oneWire(temp1pin);
DallasTemperature temp1(&oneWire);

void setup() {
  Serial.begin(9600);

  sensor.begin();

  //  pinMode(temp1pin, INPUT_PULLUP);
  temp1.begin();
}


void loop() {

  float t0 = sensor.readTemperature();
  float h0 = sensor.readHumidity();

//  temp1.requestTemperatures();
  float t1 = 24;//temp1.getTempCByIndex(0);
  int l1 = waterLevel(level1pin);


  sendButtonText(0, t0);
  sendButtonText(1, h0);
  sendButtonText(2, t1);
  sendButtonText(3, l1);

  delay(1000);
}


double L = 100.0; // длина трубки в см
// mpx5010pd
// 1 - Out
// 2 - Gnd
// 3 - Vcc
int waterLevel(int pin) {
  double p = analogRead(pin);

  // Давление водяного столба в кПа
  double h = (p / 1024 - 0.04) / 0.018 / 5.0; // kPa

  // Расчитываем поправку в см
  double l = L * h / (100.0 + h);

  int total = h * 10.0 + l;
  return total;
}

void sendButtonText(int btn, int val) {
  Serial.print("b");
  Serial.print(btn);
  Serial.print(".txt=");
  Serial.print("\""); // для текста нужны кавычки
  Serial.print(val);
  Serial.print("\""); // для текста нужны кавычки
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

