/*
 * UltraSonicHandler.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: Alex
 */

#include "UltraSonicHandler.h"
#include "Arduino.h"

UltraSonicHandler::UltraSonicHandler(int trigPin, int echoPin) {
	this->trigPin = trigPin;
	this->echoPin = echoPin;

	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

}

UltraSonicHandler::~UltraSonicHandler() {
}

// This gets a distance that we convert to -1 if it's over our threshold.
// As of right now, it's considered 'less' accurate than our
// averagedDistance method.
long UltraSonicHandler::getDistance() {
	// Send a sound pulse out
	sendPulse();
	long distance = getRawDistance();

	if (distance > DISTANCE_THRESHOLD) {
		distance = -1;
	}

	return distance;
}

// This method is used if we want to be 'somewhat' more accurate and send out
// many pulses and average them out. Anything that is over our
// distance_threshold is essentially considered an outlier and not included in
// our final calculation for average. This is suppose to be more accurate, but
// it could also be pointless math that doesn't help!
long UltraSonicHandler::getAveragedDistance(int amount) {
	int successfulCount = 0;
	double totalDistance = 0;

	for (int i = 0; i < amount; i++) {
		sendPulse();
		long distance = getRawDistance();

		if (distance > DISTANCE_THRESHOLD) {
			continue;
		}

		successfulCount += 1;
		totalDistance += distance;
	}

	long averagedDistance;

	if (successfulCount == 0) {
		averagedDistance = -1;
	} else {
		averagedDistance = totalDistance / successfulCount;
	}

	return averagedDistance;
}

// This sends a pulse with the ultra sonic sensor.
void UltraSonicHandler::sendPulse() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(SMALL_PULSE_DELAY);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(LARGE_PULSE_DELAY);
	digitalWrite(trigPin, LOW);
}

// This returns a raw distance, we don't convert or play with it's value at all
long UltraSonicHandler::getRawDistance() {
	long duration = pulseIn(echoPin, HIGH);

	// We need the time it took to get to the object, so we divide path time by 2.
	duration = duration / 2;
	long distance = duration / SPEED_OF_LIGHT_CM_CONVERSION;

	return distance;
}
