#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <vector>
#include "behavior_component.hpp"
#include "entity.hpp"

typedef int entityId_t;

class Entity
{
	public:
		~Entity();
		void render();
		void live();
		componentId_t addBehaviorComponent(BehaviorComponent* component);
	private:
		std::vector<BehaviorComponent*> behaviorComponents;	
};

#endif