#include <iostream>
#include "gravity_component.hpp"

GravityComponent::GravityComponent(Entity* e)
: BehaviorComponent(e)
{}

void GravityComponent::behave()
{
	std::cout << "gravity" << std::endl;
}