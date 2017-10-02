// Define o nome dos pinos
#define PINO_LED    13     // pino digital
#define PINO_POT    0      // pino analogico 

int valor_pot;

void setup()
{
    // prepara uma comunicação serial
    Serial.begin(9600);
	pinMode(PINO_LED, OUTPUT);
}

void loop()
{
    // retorna um valor entre 0 e 1023
    valor_pot = analogRead(PINO_POT);
    // manda p/ USB (ver com Monitor Serial)
    Serial.println(valor_pot);
    
	digitalWrite(PINO_LED, HIGH);
	delay(valor_pot);
	digitalWrite(PINO_LED, LOW);
	delay(valor_pot);    
}
