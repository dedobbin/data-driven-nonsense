#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include <memory>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "action.hpp"
#include "behavior_component.hpp"

//class Entity;

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent();
		void behave();
		void notify(std::shared_ptr<Action> action);
};

#endif