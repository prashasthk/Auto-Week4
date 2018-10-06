#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Pink_Pathway.h"
#include "CommandBase.h"

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {
		//chooser.AddDefault("Default Auto", new ExampleCommand());
		chooser.AddObject("My Auto", new Pink_Pathway());
		chooser.AddObject("My Auto", new Top_Red_Pathway());
		chooser.AddObject("My Auto", new MiddletoTop_Pathway());
		chooser.AddObject("My Auto", new MiddletoBottom_Pathway());
		chooser.AddObject("My Auto", new Bottom_Red_Pathway());
		chooser.AddObject("My Auto", new Blue_Pathway());
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}
private:



	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		autonomousCommand = chooser.GetSelected();
		std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		std::string autoString = chooser.GetName();
		if (autoString == "Mid") {
			if (gameData.length > 0) {
				if (gameData[0] == 'L') {
					autonomousCommand.reset(new MiddletoTop_Pathway());
				}
				else {
				autonomousCommand.reset(new MiddletoBottom_Pathway());
				}
			}
		}
		if (autoString == "Top") {
			if (gameData.length > 0) {
				if (gameData[0] == 'L') {
					autonomousCommand.reset(new Pink_Pathway());
				}
				else {
					autonomousCommand.reset(new Top_Red_Pathway());
				}
			}
		}

		if (autoString == "Bottom") {
			if (gameData.length > 0) {
				if (gameData[0] == 'L') {
					autonomousCommand.reset(new Bottom_Red_Pathway());
				}
				else {
					autonomousCommand.reset(new Blue_Pathway());
				}
			}
		}

		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
};

START_ROBOT_CLASS(Robot)
