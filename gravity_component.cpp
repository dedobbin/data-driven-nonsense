#include <iostream>
#include "gravity_component.hpp"
#include "entity.hpp"

GravityComponent::GravityComponent(float mass)
: mass(mass)
{}

void GravityComponent::behave()
{
	float speedIncrease = force / mass;
	auto a = new SpeedIncreaseAction(speedIncrease, dir);
	notifyAll(a);
}
