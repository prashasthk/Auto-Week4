/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Turn.h"

Turn::Turn(double angleInput):
anglePID(new WVPIDController(angleKp, angleKi, angleKd, setpoint, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	setpoint = angleInput;
	Requires(drive);
}

// Called just before this Command runs the first time
void Turn::Initialize() {
drive->resetEncoders();
drive->gyroReset();

}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	angle = drive->getAngle();
	average_encoderVal = (drive->leftDistance() + drive->rightDistance())/2;
	power = anglePID->Tick(average_encoderVal);
	double error = setpoint - angle;
	if (setpoint > 0) {
		drive->tankDrive(0.15 + power, -0.15 - power);
	}
	else {
		drive->tankDrive(-0.15 - power, 0.15 + power);
	}

}
// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() {
	return fabs(setpoint - angle) < 0.05;
}

// Called once after isFinished returns true
void Turn::End() {
	drive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
