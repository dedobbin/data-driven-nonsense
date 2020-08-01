#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include "behavior_component.hpp"

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(int ownerEntityId);
		void behave(std::vector<Action*>& actions);
};

#endif