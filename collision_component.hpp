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
			SDL_Rect* pos,	//player is owner, TODO: should go in pos component, which will signal collision component
			std::vector<std::shared_ptr<Entity>>* colliders, 
			std::unordered_map<int, collisionActionType_t>* collisionMap
		);
		void behave();
		const int ownerEntityId;
	private:
		std::vector<std::shared_ptr<Entity>>* colliders; //game is owner
		std::unordered_map<int, collisionActionType_t>* collisionMap; //game is owner
		SDL_Rect* pos = NULL;
};

#endif