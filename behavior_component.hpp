#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include <vector>
#include "action.hpp"

class Entity;

class BehaviorComponent
{
	public:
		BehaviorComponent(Entity* owner);
		virtual void behave(std::vector<Action*> &triggeredAction) = 0;
		Entity* const owner;
};

#endif