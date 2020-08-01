#include <iostream>
#include "collision_component.hpp"
#include "entity.hpp"


CollisionComponent::CollisionComponent(Entity* owner, std::vector<Entity*> colliders)
: BehaviorComponent(owner), colliders(colliders)
{}

void CollisionComponent::behave(std::vector<Action*>& actions)
{

}

