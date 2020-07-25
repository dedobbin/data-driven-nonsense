#ifndef __GRAVITY_COMPONENT_HPP__
#define __GRAVITY_COMPONENT_HPP__

#include "behavior_component.hpp"

class GravityComponent : public BehaviorComponent
{
	public:
		GravityComponent(Entity* e);
		void behave();
};

#endif