#include <iostream>
#include <memory>
#include <string>
#include <Servo.h>
#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <RobotDrive.h>
#include <Timer.h>


class ServoBot: public frc::SampleRobot {

	frc::Joystick stick { 0 };
	frc::Servo servo {8};

public:
	ServoBot() {

	}


	/*
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl() override {
		while (IsOperatorControl() && IsEnabled()) {
			double amt = (stick.GetRawAxis(3)+1)*0.5;
			frc::SmartDashboard::PutNumber("amt: ",amt);
			servo.Set(amt);

			// wait for a motor update time
			frc::Wait(0.005);
		}
	}

};

START_ROBOT_CLASS(ServoBot)
