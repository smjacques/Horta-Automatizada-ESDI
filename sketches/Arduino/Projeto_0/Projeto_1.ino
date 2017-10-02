#define PINO_LED    13     // pino digital

int pausa = 1000; 	        // millisegundos

// executada uma vez ao ligar
void setup()
{
    pinMode(PINO_LED, OUTPUT);
}

// fica executando para sempre
void loop()
{
    digitalWrite(PINO_LED, HIGH);
    delay(pausa);
    digitalWrite(PINO_LED, LOW);
    delay(pausa);
}
