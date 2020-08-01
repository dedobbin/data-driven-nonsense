#include <iostream>
#include "collision_component.hpp"
#include "entity.hpp"

bool collision()
{
	return false;
}

CollisionComponent::CollisionComponent(Entity* owner, std::vector<Entity*> colliders)
: BehaviorComponent(owner), colliders(colliders)
{}

void CollisionComponent::behave(std::vector<Action*>& actions)
{
	for (auto collider: colliders){
		if (collision()){
			
		}
	}
}

