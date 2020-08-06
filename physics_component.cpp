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
				break;
				case 1:
					xSpeed += amount;
				break;
				case 2:
					ySpeed += amount;
					break;
				case 3:
					ySpeed -= amount;
					break;
			}
			break;
		}
	}
}