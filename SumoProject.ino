#include "Arduino.h"
#include "UltraSonicHandler.h"
//The setup function is called once at startup of the sketch

const int SERIAL_DATA_TRANSMISSION_SPEED = 9600;
long cm;
// First Ultra Sonic Sensor is defined with the trig pin 3 and 5. This allows us to easily create new instances of different sensors without having to write the same code over and over.
UltraSonicHandler ultraSonicSensor1 = UltraSonicHandler(11, 12);

void setup() {
	Serial.begin(SERIAL_DATA_TRANSMISSION_SPEED);
	Serial.print("STARTING");
}

// The loop function is called in an endless
void loop() {
  long cm = ultraSonicSensor1.getAveragedDistance(10);
  Serial.print(cm);
  Serial.println();
	delay(250);
}
