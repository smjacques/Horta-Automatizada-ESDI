#define PINO_LED    13     // pino digital

int pausa = 1000;          //milisegundos

// executada uma vez ao ligar
void setup()
{    
    Serial.begin(9600);
	pinMode(PINO_LED, OUTPUT);
}

// executa repetidamente
void loop()
{    
	digitalWrite(PINO_LED, HIGH);
	delay(pausa);
	digitalWrite(PINO_LED, LOW);
	delay(pausa);    
}
