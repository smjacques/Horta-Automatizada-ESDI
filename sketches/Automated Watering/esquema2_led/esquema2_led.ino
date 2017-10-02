/*testa o % de umidade e acende o LED quando abaixo de 40%
*/

int val_umid = 0; // sensor de umidade
int umidade=0;
    
void setup() {
  Serial.begin(9600);
}

  void led(int state) {
  digitalWrite(8, state);
  }

void loop() {
  umidade = analogRead(val_umid);    
  umidade = constrain(umidade,400,1023); //intervalo dos resultados brutos entre seca e úmido
  umidade = map(umidade,400,1023,0,100); //convertendo os resultados em porcentagem de umidade (0 e 100%)

  Serial.println(umidade);
     
  if(umidade< 40) {
  led(HIGH);
  } else   {
  led(LOW);
  }

delay(2000);

    }
