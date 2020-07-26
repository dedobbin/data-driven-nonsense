#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <vector>
#include <SDL2/SDL.h>
#include "behavior_component.hpp"
#include "action.hpp"
#include "entity.hpp"

typedef int entityId_t;

class Entity
{
	public:
		~Entity();
		void live(std::vector<Action*>& triggeredActions);
		componentId_t addBehaviorComponent(BehaviorComponent* component);
	private:
		std::vector<BehaviorComponent*> behaviorComponents;	
		int spriteId = -1;
};

#endif