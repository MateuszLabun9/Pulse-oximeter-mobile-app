
#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;

const byte RATE_SIZE = 4; 
byte rates[RATE_SIZE];
byte rateSpot = 0;
long lastBeat = 0; 

float beatsPerMinute;
int beatAvg;

long temp = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Inicjalizacja...");

  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST))
  {
    Serial.println("MAX30102 nie został wykryty. ");
    while (1);
  }

  particleSensor.setup(); 
  particleSensor.setPulseAmplitudeRed(0x0A); 
  particleSensor.setPulseAmplitudeGreen(0); 
}

void loop()
{
  long irValue = particleSensor.getIR();
  long span = millis() - temp;

  if (checkForBeat(irValue) == true)
  {
    //We sensed a beat!
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; 
      rateSpot %= RATE_SIZE; 
     
     
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  
  if(span - temp  >= 1500){
    if (irValue < 50000){
    Serial.println(" Przyłóż palec do czujnika ");
    Serial.println();
    }
    
    long irValueNew = irValue;
    float beatsPerMinuteNew = beatsPerMinute;
    int beatAvgNew = beatAvg;
    Serial.println(beatAvgNew);
  
    temp = span;
    
  
    
  }
  
}
