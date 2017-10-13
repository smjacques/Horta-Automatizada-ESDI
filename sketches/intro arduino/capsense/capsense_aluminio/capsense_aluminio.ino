#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2);        
// 10M resistor between pins 4 & 2, pin 2 is sensor pin
// add a wire and or foil if desired

int receivePin = 2;
int sendPin = 4;
int ledPin1 = 10;
int ledPin2 = 9;

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   // above: turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(ledPin1, OUTPUT); 
   pinMode(ledPin2, OUTPUT);

}

void loop()                    
{
    long start = millis();
    long total =  cs_4_2.capacitiveSensor(30);

    Serial.print(millis() - start);        
    // check on performance in milliseconds

    Serial.print("\t");                    
    // tab character for debug windown spacing

    Serial.print(total);                   
    // print sensor output

    Serial.println();

    // parameters to set level for PWM output
    float level1;
    float level2;
    float threshold1 = 40;
    float threshold2 = 60;
    float max = 60;


    if (total < threshold1) {
       level1 = 0;
     }
     else {
       level1= map(total,threshold1,max,0,1023);
     }
 
     if (total < threshold2) {
       level2 = 0;
     }
     else {
       level2= map(total,threshold2,max,0,1023);
     }
 
 
     analogWrite(ledPin1,level1);
     analogWrite(ledPin2,level2);


    delay(1);  // arbitrary delay to limit data to serial port 
}
