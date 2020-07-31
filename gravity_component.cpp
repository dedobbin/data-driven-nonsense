#include <iostream>
#include "gravity_component.hpp"

gravityComponentponent::gravityComponentponent(int ownerEntityId)
:BehaviorComponent(ownerEntityId)
{}

void gravityComponentponent::behave(std::vector<Action*> &actions)
{
	acceleration += force / mass;
	actions.push_back(new MoveEntityAction(ownerEntityId, acceleration, dir));
}