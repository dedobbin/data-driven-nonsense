#include <iostream>
#include "collision_component.hpp"

CollisionComponent::CollisionComponent(int ownerEntityId)
: BehaviorComponent(ownerEntityId)
{}

void CollisionComponent::behave(std::vector<Action*>& actions)
{
	std::cout << "TODO: check for collision" << std::endl; 
}

