#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include <memory>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "action.hpp"
#include "behavior_component.hpp"



class Entity;

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent(
			int ownerEntityId,
			SDL_Rect pos,
			std::vector<std::shared_ptr<Entity>>* colliders, 
			std::unordered_map<int, collisionActionType_t>* collisionMap
		);
		void behave();
		const int ownerEntityId;
		void notify(std::shared_ptr<Action> action);
	private:
		std::vector<std::shared_ptr<Entity>>* colliders; //game is owner
		std::unordered_map<int, collisionActionType_t>* collisionMap; //game is owner
		SDL_Rect pos;
};

#endif