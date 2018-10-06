#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "../Utilities/PIDController.h"

class DriveForward : public CommandBase {
private:
double setpoint;
double distKp = 0.05;
double distKi = 0;
double distKd = 0;
double angle = 0;
double average_encoderDistance = 0;
double power = 0;

PIDController * drivingPID;



public:
	DriveForward(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForward_H
