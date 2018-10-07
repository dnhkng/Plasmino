#include "toneAC.h"
#include "toneAC3.h"
#include <Wire.h>
#include "VL53L0X.h"

VL53L0X sensor;

// Melody liberated from the toneMelody Arduino example sketch by Tom Igoe.
int melody[] = { 262, 196, 196, 220, 196, 0, 247, 262 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
uint16_t distance = 1;

float notes[] = { // http://www.phy.mtu.edu/~suits/notefreqs.html
  32.703,
  34.648,
  36.708,
  38.891,
  41.203,
  43.654,
  46.249,
  48.999,
  51.913,
  55,
  58.27,
  61.735 ,
  65.406 ,
  69.296  ,
  73.416 ,
  77.782 ,
  82.407 ,
  87.307,
  92.499 ,
  97.999,
  103.826 ,
  110 ,
  116.541 ,
  123.471 ,
  130.813,
  138.591,
  146.832 ,
  155.563 ,
  164.814  ,
  174.614  ,
  184.997,
  195.998,
  207.652,
  220,
  233.082 ,
  246.942,
  261.626,
  277.183,
  293.665,
  311.127,
  329.628,
  349.228,
  369.994,
  391.995,
  415.305,
  440,
  466.164,
  493.883,
  523.251,
  554.365,
  587.33,
  622.254,
  659.255,
  698.456,
  739.989,
  783.991,
  830.609,
  880,
  932.328,
  987.767,
  1046.502,
  1108.731,
  1174.659,
  1244.508,
  1318.51,
  1396.913,
  1479.978,
  1567.982,
  1661.219,
  1760
};

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000L);


  sensor.init();
  sensor.setTimeout(500);
  sensor.setSignalRateLimit(0.1);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous();
}
void loop() {


  distance = sensor.readRangeContinuousMillimeters();
  Serial.println(distance);
  if (distance < 40 || distance > 400) {
    noToneAC3();
  }
  else {
    //int d = distance/1000.0*60.0;
    //float distance = notes[d];
    toneAC3(2, 3, distance, 0, true); // Play thisNote at full volume for noteDuration in the background.

    //if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
    //Serial.println();
    //delay(noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
  }


  //while(1); // Stop (so it doesn't repeat forever driving you crazy--you're welcome).
}
