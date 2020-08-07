#include "action.hpp"

Action::Action(actionType_t type)
: type(type)
{}

SpeedIncreaseAction::SpeedIncreaseAction(float speed, int dir)
: Action (SPEED_INCREASE), speed(speed), dir(dir)
{}

MoveEntityAction::MoveEntityAction(float x, float y)
: Action (MOVE_ENTITY), x(x), y(y)
{}

CollisionAction::CollisionAction(collisionActionType_t collisionType)
: Action (COLLISION), collisionActionType(collisionType)
{}