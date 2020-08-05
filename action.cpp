#include "action.hpp"

Action::Action(actionType_t type)
: type(type)
{}

SpeedIncreaseAction::SpeedIncreaseAction(int speed, int dir)
: Action (SPEED_INCREASE), speed(speed), dir(dir)
{}