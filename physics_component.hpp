#ifndef __PHYSICS_COMPONENT_HPP__
#define __PHYSICS_COMPONENT_HPP__

#include "behavior_component.hpp"

#define LAST_MOVE_DIR_X 1
#define LAST_MOVE_DIR_Y 2

class PhysicsComponent : public BehaviorComponent
{
	public:
		void behave();
		void notify(std::shared_ptr<Action> action);
	private:
		float xSpeed;
		float ySpeed;
		int lastMoveDir = 0; 
		bool hasSolidCollision = false;
};

#endif