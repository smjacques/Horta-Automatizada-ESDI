// Incluir bibliotecas prontas
#include "pincapsense.h"
#define PINO_LED      12   // pino digital
#define PINO_BUZZER   3    // pino digital PWM
#define PINO_CAP      2    // pino sensor cap.
#define NOTA_E7       2637 // Hz



int valor_cap;

void setup() {
	pinMode(PINO_LED, OUTPUT);
	pinMode(PINO_BUZZER, OUTPUT);
}

void loop() {
	valor_cap = readCapacitivePin(PINO_CAP);
	Serial.println(valor_cap);	
    
	if (valor_cap > 6) {  // tocou na banana?
		digitalWrite(PINO_LED, HIGH);
		tone(PINO_BUZZER, NOTA_E7);
	}
	else {
		digitalWrite(PINO_LED, LOW);
		noTone(PINO_BUZZER);
	}
	delay(200);
}
