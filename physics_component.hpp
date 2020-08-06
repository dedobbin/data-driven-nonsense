#ifndef __PHYSICS_COMPONENT_HPP__
#define __PHYSICS_COMPONENT_HPP__

#include "behavior_component.hpp"

class PhysicsComponent : public BehaviorComponent
{
	public:
		void behave();
		void notify(Action* action);
	private:
		float xSpeed;
		float ySpeed;
};

#endif