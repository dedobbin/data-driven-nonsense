#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include "behavior_component.hpp"

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(Entity* owner, std::vector<Entity*> colliders);
		void behave(std::vector<Action*>& actions);
	private:
		std::vector<Entity*> colliders;
};

#endif