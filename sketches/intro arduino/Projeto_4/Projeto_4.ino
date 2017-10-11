#define PINO_BUZZER   3   // pino digital PWM
#define LDRpin A0 // pino do LDR

float val_lum, periodo = 200;
int luminosidade;


void setup() {
  pinMode(PINO_BUZZER, OUTPUT);
  pinMode(LDRpin, INPUT);
  Serial.begin(9600);
}

void loop() {
 val_lum = analogRead(LDRpin);
 luminosidade = val_lum*9.77; // esse valor foi calculado para que o som emitido seja "bonito"

 Serial.write("Luminosidade: ");
 Serial.println(luminosidade); 
 
 tone(PINO_BUZZER, luminosidade);
 delay(periodo);
}
