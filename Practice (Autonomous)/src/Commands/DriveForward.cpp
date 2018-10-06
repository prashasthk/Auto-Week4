#include "DriveForward.h"
#include "../CommandBase.h"


DriveForward::DriveForward(double distance) :
drivingPID(new WVPIDController(distKp, distKi, distKd, setpoint, false)){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	setpoint = distance;
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	drive->resetEncoders();
	drive->gyroReset();
	angle = drive->getAngle();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute(){
	 average_encoderDistance = (drive->leftDistance() + drive->rightDistance())/2;
	 power = drivingPID->Tick(average_encoderDistance);
	 double angleError = drive->getAngle() - angle;
	drive->tankDrive(0.15 + power + angleError/10, 0.15 + power - angleError/10);
	}




// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return fabs(average_encoderDistance - setpoint) < 0.05;
}
// Called once after isFinished returns true
void DriveForward::End() {
	drive->tankDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
