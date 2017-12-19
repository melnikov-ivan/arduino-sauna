#include <Nextion.h> // https://github.com/itead/ITEADLIB_Arduino_Nextion

void setup() {
  Serial.begin(9600);

}

int var = 0;
void loop() {
  
  sendButtonText(0, var);

  var++;
  delay(1000);
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


//#include "Adafruit_Si7021.h"
//Adafruit_Si7021 sensor = Adafruit_Si7021();
//sensor.begin();
//Serial.print(sensor.readHumidity(), 2);
//Serial.println(sensor.readTemperature(), 2);
  

