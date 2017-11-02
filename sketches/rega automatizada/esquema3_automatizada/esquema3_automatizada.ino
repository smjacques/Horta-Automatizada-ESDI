/*Rega ativada pela baixa umidade detectada (nesse caso, abaixo 40%),
a solenoide fecha quando o % ultrapassa 40%.
*/

int val_umid = 0; // sensor de umidade
int solenoide = 4; // ativar e desativar rega
    
    
void setup() {
   Serial.begin(9600);
}
     
    void rega(int state) {
        digitalWrite(solenoide, state);
    }
     
void loop() {
     int umidade = analogRead(val_umid);    
     umidade = constrain(umidade,400,1023);
     umidade = map(umidade,400,1023,100,0);

     
 Serial.println(umidade);
     
        if(umidade< 40) {
            rega(HIGH);
        } else   {
            rega(LOW);
        }
        delay(2000);

    }
