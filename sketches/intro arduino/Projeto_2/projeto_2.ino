
float val_lum;
int luminosidade;
byte LDRpin=A0, LED=13; 

void setup() {
  Serial.begin(9600);
}

void loop() {
 val_lum = analogRead(LDRpin);
 luminosidade = val_lum*0.0977; // regra de três

 Serial.write("Luminosidade: ");
 Serial.println(luminosidade); 
 
 if (luminosidade <50) {
   digitalWrite(LED, HIGH);
 }
else {
  digitalWrite(LED,LOW);
 }

delay(1000); 
}
