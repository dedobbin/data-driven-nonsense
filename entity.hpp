#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <vector>
#include <SDL2/SDL.h>
#include "action.hpp"
#include "behavior_component.hpp"
#include "entity.hpp"

class Entity 
{
	public:
		~Entity();
		void live();
		void addBehaviorComponent(std::shared_ptr<BehaviorComponent> component);
		void removeBehaviorcomponent(int index);
		int spriteId = -1;
		int id = -1;
		void notify(std::shared_ptr<Action> action);
	private:
		std::vector<std::shared_ptr<BehaviorComponent>> behaviorComponents;	
};

#endif