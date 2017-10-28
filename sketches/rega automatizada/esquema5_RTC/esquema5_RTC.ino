// Carrega a biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>

//Sensor de umidade
int val_umid = 0;
int umidade=0;

// Valvula solenoide
int solenoide = 7; // ativar led quando seco

// Determina os pinos ligados ao modulo
// myRTC(clock, data, rst)
virtuabotixRTC myRTC(10, 9, 8);

const int H1 = 17; // hora medida 1
const int M1 = 07; // minuto medida 1

const int H2 = 17; // hora medida 2
const int M2 = 11; // minuto medida 2

// Denfinindo umidade limite e tempo de rega
const int umidade_min = 40; // 80%

int TempoRega = 10000; //10 secs operando

    
void setup() {
  Serial.begin(9600);
  //certifica-se que a solenoide inicia deligada (LOW)
  digitalWrite(solenoide, LOW);
  //define como saida
  pinMode(solenoide, OUTPUT);
  
}

void loop()
{
  // Le as informacoes do CI
  myRTC.updateTime();
  imprime_tempo();

  int hora = myRTC.hours;
  int minutos = myRTC.minutes;
  
  // verifica se chegou a hora de ler a umidade
  if ((hora == H1 && minutos == M1) || (hora == H2 && minutos == M2) ) {
    Serial.println("medindo...");
    // ler umidade
    umidade = analogRead(val_umid);    
    umidade = constrain(umidade,400,1023); //intervalo entre seca e úmido
    umidade = map(umidade,400,1023,100,0); // convertendo em %
    imprime_umidade();
    
    // verifica se a umidade está abaixo do minimo
    if (umidade < umidade_min ) {
      Serial.println("abrindo válvula...");
      digitalWrite(solenoide, HIGH);
      delay(TempoRega);
      Serial.println("fechando valvula...");
      digitalWrite(solenoide, LOW);
    } // fim do if da umidade
  }
}


void imprime_umidade() {
  Serial.print("Umidade : ");
  Serial.print(umidade);
  Serial.println("%");
}
void imprime_tempo() {
  // Imprime as informacoes no serial monitor
  Serial.print("Data : ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  // Adiciona um 0 caso o valor da hora seja <10
  if (myRTC.hours < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.hours);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (myRTC.minutes < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);
}

