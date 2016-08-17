#ifndef MOTORHANDLER_H_
#define MOTORHANDLER_H_

// The motor handler class is used for creating a motor object to
// easily tell it things to do. This is to avoid having to manually
// write these digital writes every time you want the motor to do
// 'something', but this also has the benefit of controlling several
// motors easily.
class MotorHandler {
	public:
		/**
		 * Intializes a Motor object.
		 * Takes in the logic pins and pwm pins of the motor.
		 */
		MotorHandler(int logicPin1, int logicPin2, int pwmPin);
		virtual ~MotorHandler();

		/**
		 * Sets both motor states to LOW, stopping the motor.
		 */
		void stop();

		/**
		 * Sets the speed of the motor to run.
		 * Takes in a percentage between 0-100 (not 0)
		 */
		void setSpeed(int percentage);

		/**
		 * Sets the motor state to forward
		 */
		void setForward();

		/**
		 * Sets the motor state to reverse
		 */
		void setReverse();
	private:
		int logicPin1;
		int logicPin2;
		int pwmPin;
		const int MAX_PWM = 255;
};

#endif /* MOTORHANDLER_H_ */
