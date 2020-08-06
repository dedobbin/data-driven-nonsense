#include "action.hpp"

Action::Action(actionType_t type)
: type(type)
{}

SpeedIncreaseAction::SpeedIncreaseAction(int speed, int dir)
: Action (SPEED_INCREASE), speed(speed), dir(dir)
{}

MoveEntityAction::MoveEntityAction(float x, float y)
: Action (MOVE_ENTITY), x(x), y(y)
{}

