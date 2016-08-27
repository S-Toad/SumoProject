/*
 * MotorHandler.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: Alex
 */

#include "Arduino.h"
#include "MotorHandler.h"

MotorHandler::MotorHandler(int logicPin1, int logicPin2, int pwmPin) {
	this->logicPin1 = logicPin1;
	this->logicPin2 = logicPin2;
	this->pwmPin = pwmPin;

	pinMode(logicPin1, OUTPUT);
	pinMode(logicPin1, OUTPUT);
	pinMode(pwmPin, OUTPUT);
}

MotorHandler::~MotorHandler() {
}

void MotorHandler::setSpeed(int percentage) {
	// To be safe, if this code was used with a negative or a
	// value higher than 100, it'll return with a warning. It
	// also doesn't allow 0, stopping should be done with stop()
	if (percentage <= 0 || percentage > 100) {
		Serial.println(
				"WARNING: Speed percentage was set at a value out of the range of 1-100");
		return;
	}

	// This gets the percentage value in terms of the MAX_PWM,
	// (which is 255). So 100% as our input should define as
	// 255. 50% should be defined as 127 (and not 127.5) and so on.
	int pwmValue = (percentage / 100.0) * MAX_PWM;
	analogWrite(pwmPin, pwmValue);
}

// As per the description of the Motor Controller, setting
// LOW to both logic pins will stop the motor.
void MotorHandler::stop() {
	digitalWrite(logicPin1, LOW);
	digitalWrite(logicPin2, LOW);
	analogWrite(pwmPin, 0);
}

// This may end up going the other way, if such a thing happens,
// the user needs to switch the logic pins in the constructor as
// the code can not guess how the motor is connected!
void MotorHandler::setForward() {
	digitalWrite(logicPin1, HIGH);
	digitalWrite(logicPin2, LOW);
}

// Same as setForward(), switching the logic pins in the constructor
// will correct any issues.
void MotorHandler::setReverse() {
	digitalWrite(logicPin1, LOW);
	digitalWrite(logicPin2, HIGH);
}

