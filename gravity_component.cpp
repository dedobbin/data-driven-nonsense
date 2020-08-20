#include <iostream>
#include "gravity_component.hpp"

GravityComponent::GravityComponent(Entity* owner, float mass)
: BehaviorComponent(owner), mass(mass)
{}

void GravityComponent::behave()
{
	float speedIncrease = force / mass;
	auto a = std::make_shared<SpeedIncreaseAction>(speedIncrease, dir);
	notifyAll(a);
}
