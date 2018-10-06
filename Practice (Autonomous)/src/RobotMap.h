#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

constexpr int LEFTMOTOR = 3;
constexpr int RIGHTMOTOR = 4;
constexpr int LIFT_MOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;
constexpr int Pink_Blue_forward = 149;
constexpr int Pink_Blue_turnRight = 19.56;
constexpr int forwardRed = 56.735;
constexpr int turnRed = 221.12;
constexpr int middle_forward = 64;
constexpr int middle_turn_vertical = 36;
constexpr int middle_turn_horizontal = 45;




#endif  // ROBOTMAP_H
