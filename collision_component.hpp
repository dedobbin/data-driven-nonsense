#ifndef __COLLISION_COMPONENT__
#define __COLLISION_COMPONENT__

#include <memory>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "action.hpp"
#include "behavior_component.hpp"

struct CollisionWrapper;

class CollisionComponent : public BehaviorComponent
{
	public:
		CollisionComponent();
		void behave();
		void notify(std::shared_ptr<Action> action);
	private:
		static std::vector<CollisionWrapper> colMap;
};

struct CollisionWrapper 
{
	int entityId = -1;
	std::shared_ptr<CollisionComponent> col;
	collisionType_t type = NONE;
};

#endif