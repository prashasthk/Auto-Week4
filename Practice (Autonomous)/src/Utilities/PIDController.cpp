
#include "PIDController.h"

PIDController::PIDController(double Kp, double Ki, double Kd, double setPoint, bool integralThreshold) :
lastPWM(0), error(0) {
	this -> Kp = Kp;
	this-> Ki = Ki;
		this-> Kd = Kd;
		this->setPoint = setPoint;
		this->integralThreshold = integralThreshold;
		error = 0;
		previousError = 0.0;
		integral = 0.0;
		lastPWM = 0;
	}

	double PIDController::Tick(double encoderDistance) {
		error = setPoint - encoderDistance;
		if (integralThreshold) {
			if (error <= .1)
				integral += error;
		} else
			integral += error;
		double derivative = error - previousError;
		previousError = error;

		lastPWM = Kp * error + Ki * integral + Kd * derivative;
		return lastPWM;
	}

	void PIDController::SetSetPoint(double setPoint) {
		this->setPoint = setPoint;
		integral = 0;
		previousError = 0;
		error = 0;
	}

	double PIDController::GetSetPoint() {
		return setPoint;
	}

	void PIDController::SetKp(double Kp) {
		this->Kp = Kp;
	}

	double PIDController::GetKp() {
		return Kp;
	}

	void PIDController::SetKi(double Ki) {
		this->Ki = Ki;
	}

	double PIDController::GetKi() {
		return Ki;
	}

	void PIDController::SetKd(double Kd) {
		this->Kd = Kd;
	}

	double PIDController::GetKd() {
		return Kd;
	}

	double PIDController::GetError() {
		return error;
	}

	double PIDController::GetLastPWM() {
		return lastPWM;
	}



