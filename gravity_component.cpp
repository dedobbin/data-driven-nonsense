#include <iostream>
#include "gravity_component.hpp"

GravityComponent::GravityComponent(int ownerEntityId)
:BehaviorComponent(ownerEntityId)
{}

void GravityComponent::behave(std::vector<Action*> &actions)
{
	acceleration += force / mass;
	actions.push_back(new MoveEntityAction(ownerEntityId, acceleration, dir));
}