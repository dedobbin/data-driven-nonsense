#include <iostream>
#include "gravity_component.hpp"
#include "entity.hpp"


GravityComponent::GravityComponent(Entity* owner)
:BehaviorComponent(owner)
{}

void GravityComponent::behave(std::vector<Action*> &actions)
{
	acceleration += force / mass;
	actions.push_back(new MoveEntityAction(owner->getId(), acceleration, dir));
}