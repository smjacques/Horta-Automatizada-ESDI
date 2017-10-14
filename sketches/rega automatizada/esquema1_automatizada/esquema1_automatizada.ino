/*sketch simples, mostrando apenas o output com resultados da umidade
Bom notar as infos de "umidade" (%) e "umidade_volt" (valor bruto)
*/

const int val_umid = 0; // Analog pin 0
     
void setup() {
    Serial.begin(9600);
}
     
void loop() {
  int umidade_volt = analogRead(val_umid);
  int umidade = umidade_volt;
  umidade = constrain(umidade_volt,400,1023);
  umidade = map(umidade,400,1023,100,0);

  Serial.println("Umidade (valor bruto)");
  Serial.println(umidade_volt);
  Serial.println("Umidade (%)");
  Serial.println(umidade);
  delay(2000);
  
}
