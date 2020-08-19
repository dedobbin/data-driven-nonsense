#include <iostream>
#include "action.hpp"

Action::Action(actionType_t type)
: type(type)
{
	//std::cout << "DEBUG: Action of type " << type << " created" << std::endl;
}

Action::~Action()
{
	//std::cout << "DEBUG: Action deconstructor called" << std::endl; 
}

SpeedIncreaseAction::SpeedIncreaseAction(float speed, int dir)
: Action (SPEED_INCREASE), speed(speed), dir(dir)
{}

MoveEntityAction::MoveEntityAction(float x, float y)
: Action (MOVE_ENTITY), x(x), y(y)
{}

CollisionAction::CollisionAction(collisionType_t collisionType)
: Action (COLLISION), collisionType(collisionType)
{}