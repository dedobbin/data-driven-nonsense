#include <iostream>
#include "physics_component.hpp"


void PhysicsComponent::behave()
{
	for (auto observer : observers){
		MoveEntityAction* action = new MoveEntityAction(xSpeed, ySpeed);
		observer->notify(action);
	}
}

void PhysicsComponent::notify(Action* action)
{
	switch(action->type){
		case SPEED_INCREASE: {
			auto speedIncreaseAction = (SpeedIncreaseAction*)action;
			float amount = speedIncreaseAction->speed;
			switch (speedIncreaseAction->dir){
				case 0:
					ySpeed -= amount;
					lastMoveDir = LAST_MOVE_DIR_Y;
					break;
				case 1:
					xSpeed += amount;
					lastMoveDir = LAST_MOVE_DIR_X;
					break;
				case 2:
					ySpeed += amount;
					lastMoveDir = LAST_MOVE_DIR_Y;
					break;
				case 3:
					ySpeed -= amount;
					lastMoveDir = LAST_MOVE_DIR_X;
					break;
			}
			break;
		}
		case COLLISION :{
			auto collisionAction = (CollisionAction*)action;
			switch (collisionAction->collisionActionType){
				case SOLID:{
					std::cout << "solid collision " << std::endl;
					break;
				}
				default:{
					std::cerr << "unknown collision type " << std::endl;
					break;
				}
			}
			break;
		}
	}
}