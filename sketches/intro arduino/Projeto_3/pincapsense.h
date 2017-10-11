/*
  pincapsense.h 
  http://playground.arduino.cc/Code/CapacitiveSensor
  
  Use any Arduino pin as a capacitive sensor without any additional
  hardware but a wire on the pin.
*/

// ensure this library description is only included once
#ifndef pincapsense_h
#define pincapsense_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

typedef unsigned char uint8_t; 

uint8_t readCapacitivePin(int pinToMeasure);

#endif
