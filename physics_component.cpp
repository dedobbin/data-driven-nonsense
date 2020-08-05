#include <iostream>
#include "physics_component.hpp"


PhysicsComponent::PhysicsComponent(Entity* owner)
: BehaviorComponent(owner)
{

}
void PhysicsComponent::behave()
{

}

void PhysicsComponent::notify(Action* action)
{
	//TODO: actually change x and y, should owner be observer???
	std::cout << "TODO: physics component got action, change state etc" << std::endl;
}