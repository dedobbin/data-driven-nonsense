#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include "behavior_component.hpp"

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(Entity* owner, std::vector<Entity*>* colliders);
		void behave();
	private:
		std::vector<Entity*>* colliders; //game is owner
};

#endif