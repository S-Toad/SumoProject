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
		UltraSonicHandler(int trigPin, int echoPin);
		virtual ~UltraSonicHandler();
		long getDistance();
		long getAveragedDistance(int amount);
		long getRawDistance();
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
