/*Rega definida pelo tempo de abertura da solenoide a partir do momento
que a umidade esteja abaixo de um % estabelecido (nesse caso, 40%)
*/

int val_umid = 0; // sensor de umidade
int umidade=0;
int solenoide = 4; // ativar led quando seco    
int TempoRega = 10000; //definir tempo de rega (10 secs operando)
    
void setup() {
  Serial.begin(9600);
  pinMode(solenoide, OUTPUT); //pin do solenoide
  digitalWrite(solenoide, LOW); //certifica-se que a solenoide inicia deligada (LOW)
}
     
void loop() {
  umidade = analogRead(val_umid);    
  umidade = constrain(umidade,400,1023); //intervalo entre seca e úmido
  umidade = map(umidade,400,1023,100,0);
     
     
 Serial.println(umidade);
     
  if (umidade < 40) {
  digitalWrite(solenoide, HIGH);
  delay(TempoRega);
  digitalWrite(solenoide, LOW);
    }
}
