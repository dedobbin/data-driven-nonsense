#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include <memory>
#include <vector>
#include <unordered_map>
#include "action.hpp"
#include "behavior_component.hpp"



class Entity;

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(
			std::shared_ptr<Entity> owner,
			std::vector<std::shared_ptr<Entity>>* colliders, 
			std::unordered_map<int, collisionActionType_t>* collisionMap
		);
		void behave();
	private:
		std::shared_ptr<Entity> owner;
		std::vector<std::shared_ptr<Entity>>* colliders; //game is owner
		std::unordered_map<int, collisionActionType_t>* collisionMap; //game is owner
};

#endif