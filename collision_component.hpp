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
		CollisionComponent(Entity* owner, collisionType_t type);
		~CollisionComponent();
		void behave();
		void notify(std::shared_ptr<Action> action);
	private:
		static std::unordered_map<int, CollisionWrapper> colMap;//entity id = key
};

struct CollisionWrapper 
{
	CollisionComponent* col;
	collisionType_t type = NONE;
};

#endif