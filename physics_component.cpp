#include <iostream>
#include "helpers.hpp"
#include "physics_component.hpp"

PhysicsComponent::PhysicsComponent(Entity* owner, float xSpeed, float ySpeed)
:BehaviorComponent(owner), xSpeed(xSpeed), ySpeed(ySpeed)
{}

void PhysicsComponent::behave()
{
	int x = xSpeed;
	int y = ySpeed;
	if (hasSolidCollision){
		hasSolidCollision = false;
		if (lastMoveDir == LAST_MOVE_DIR_Y){
			y = 0;
		} else if (lastMoveDir == LAST_MOVE_DIR_Y){
			x = 0;
		}
	}
	//std::cout << "DEBUG speed:" << xSpeed << "," << ySpeed << std::endl;
	auto action = std::make_shared<MoveEntityAction>(x, y);
	notifyAll(action);
}

void PhysicsComponent::notify(std::shared_ptr<Action> action)
{
	switch(action->type){
		case SPEED_INCREASE: {
			auto speedIncreaseAction = std::static_pointer_cast<SpeedIncreaseAction>(action);
			float amount = speedIncreaseAction->speed;
			if (speedIncreaseAction->dir == 0){
				xSpeed += amount;
				lastMoveDir = LAST_MOVE_DIR_X;
				notifyAll(std::make_shared<SetPropertyAction>(X_SPEED, xSpeed));	
			} else if (speedIncreaseAction->dir == 1){
				ySpeed += amount;
				lastMoveDir = LAST_MOVE_DIR_Y;	
				notifyAll(std::make_shared<SetPropertyAction>(Y_SPEED, ySpeed));	
			}
			// switch (speedIncreaseAction->dir){
			// 	case 0:
			// 		ySpeed -= amount;
			// 		lastMoveDir = LAST_MOVE_DIR_Y;
			// 		break;
			// 	case 1:
			// 		xSpeed += amount;
			// 		lastMoveDir = LAST_MOVE_DIR_X;
			// 		break;
			// 	case 2:
			// 		ySpeed += amount;
			// 		lastMoveDir = LAST_MOVE_DIR_Y;
			// 		break;
			// 	case 3:
			// 		ySpeed -= amount;
			// 		lastMoveDir = LAST_MOVE_DIR_X;
			// 		break;
			// }
			break;
		}
		case COLLISION :{
			auto collisionAction = std::static_pointer_cast<CollisionAction>(action);
			switch (collisionAction->collisionType){
				case SOLID:{
					hasSolidCollision = true;
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