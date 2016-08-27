#include "MotorHandler.h"
MotorHandler motorTest(8, 9, 10);

void setup() {
	Serial.begin(9600);
	Serial.print("STARTING");
}

void loop() {
	motorTest.setForward();
	motorTest.setSpeed(100);
	delay(5000);
	motorTest.setReverse();
	delay(5000);
	motorTest.setSpeed(50);
	delay(5000);
	motorTest.stop();
	delay(5000);
}

