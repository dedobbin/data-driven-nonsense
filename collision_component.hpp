#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include <unordered_map>
#include "behavior_component.hpp"

class Entity;

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(
			Entity* owner, std::vector<Entity*>* colliders, 
			std::unordered_map<int, collisionActionType_t>* collisionMap
		);
		void behave();
	private:
		const Entity* const owner;
		std::vector<Entity*>* colliders; //game is owner TODO: can use alias?
		std::unordered_map<int, collisionActionType_t>* collisionMap; //game is owner TODO: can use alias?
		int ownerEntityId;
};

#endif