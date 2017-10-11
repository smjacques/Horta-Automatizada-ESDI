/*sketch simples, mostrando apenas o output com resultados da umidade
Bom notar as infos de "umidade" (%) e "val_umid" (valor bruto)
*/

const int val_umid = 0; // Analog pin 0
     
void setup() {
    Serial.begin(9600);
}
     
void loop() {
  int umidade = analogRead(val_umid);    
  umidade = constrain(umidade,400,1023);
  umidade = map(umidade,400,1023,100,0);

  Serial.println("Umidade (valor bruto)");
  Serial.println(val_umid);
  Serial.println("Umidade (%)");
  Serial.println(umidade);
  
}
