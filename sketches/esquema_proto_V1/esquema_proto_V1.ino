// Carrega a biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Sensor de umidade
int val_umid = 0;
int umidade=0;

// Valvula solenoide
int solenoide = 4; // ativar led quando seco

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
  lcd.begin(16, 2); 
  digitalWrite(solenoide, LOW);
  //define como saida
  pinMode(solenoide, OUTPUT);
  
}

void loop()
{
  //Limpa a tela do LCD
  lcd.clear();  
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("ESDI - UERJ");
delay(500);
  lcd.setCursor(1, 1);
  lcd.print("Espacos Verdes ESDI");
  delay(1200);
  
  // Ler as informacoes do CI
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
  
  //LCD output
  
  //Limpar a tela do LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  //Texto para o LCD
  lcd.print("lendo umidade"); 
  delay(300);
  lcd.setCursor(13, 0);
  lcd.print("."); 
  delay(300);
  lcd.setCursor(13, 0);
  lcd.print(".."); 
  delay(300);
  lcd.setCursor(13, 0);
  lcd.print("..."); 
  delay(300);
  lcd.setCursor(6, 1); //Posiciona o cursor na coluna 6, linha 1;
  lcd.print(umidade);
  lcd.setCursor(9, 1);
  lcd.print("%");
  delay(1500);
     
  if(umidade< umidade_min) {
  lcd.clear();//Limpa a tela do LCD
  lcd.setCursor(2, 0);//Posiciona o cursor na coluna 2, linha 0;
  lcd.print("umidade baixa");
  delay(500);
  lcd.setCursor(5, 1);
  lcd.print("REGAR");
  delay(300);
  lcd.setCursor(10, 1);
  lcd.print("!");
  } else   {
  lcd.clear();//Limpa a tela do LCD
  lcd.setCursor(2, 0);
  lcd.print("umidade OK");
  delay(500);
  lcd.setCursor(1, 1);
  delay(300);
  lcd.setCursor(15, 1);
lcd.print("!");
  }
}


