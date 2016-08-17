/*
 * UltraSonicHandler.h
 *
 *  Created on: Aug 13, 2016
 *      Author: Alex
 */

#ifndef COMPONENT_HANDLER_ULTRASONIC_ULTRASONICHANDLER_H_
#define COMPONENT_HANDLER_ULTRASONIC_ULTRASONICHANDLER_H_

class UltraSonicHandler {
	public:
		/**
		 * Intializes a Ultra Sonic Sensor
		 * Takes in the int value of the trig and echo pins.
		 */
		UltraSonicHandler(int trigPin, int echoPin);
		virtual ~UltraSonicHandler();

		/**
		 * Sends a pulse and translates the data into distance
		 * Returns the distance in cm (-1 if greater than the threshold)
		 */
		long getDistance();

		/**
		 * Sends out several pulses and averages the results.
		 * Takes in the amount of times to iterate
		 * Returns averaged distance in cm (-1 if greater than threshold)
		 */
		long getAveragedDistance(int amount);

		/**
		 * Sends out a pulse and returns the data
		 * Returns unaltered cm distance.
		 */
		long getRawDistance();

		/**
		 * Sends out a pulse
		 * Probably wouldn't be used typically by itself.
		 */
		void sendPulse();
	private:
		int trigPin;
		int echoPin;
		const int SMALL_PULSE_DELAY = 5;
		const int LARGE_PULSE_DELAY = 10;
		const float SPEED_OF_LIGHT_CM_CONVERSION = 29.1;
		const int DISTANCE_THRESHOLD = 50;
};

#endif /* COMPONENT_HANDLER_ULTRASONIC_ULTRASONICHANDLER_H_ */
