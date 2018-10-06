/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../CommandBase.h"
#include "../Utilities/PIDController.h"

class Turn : public CommandBase{
private:
double setpoint;
double error;
double angleKp = 0.03;
double angleKi = 0;
double angleKd = 0;
double power = 0;
double average_encoderVal;
double angle = 0;
PIDController * anglePID;
public:
	Turn(double angleInput);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

