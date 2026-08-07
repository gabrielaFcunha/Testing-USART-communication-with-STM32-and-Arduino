#include <Arduino.h>
#include <string.h>

char resposta[200];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Ola, STM32!");
  delay(1000);
  if(Serial.available() > 0){
    int bytesLidos = Serial.readBytesUntil('\n', resposta, 199);
    resposta[bytesLidos] = '\0';
    Serial.print("Recebi: ");
    Serial.println(resposta);
  }
}
