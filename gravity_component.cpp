#include <iostream>
#include "gravity_component.hpp"
#include "entity.hpp"


GravityComponent::GravityComponent(Entity* owner)
:BehaviorComponent(owner)
{}

void GravityComponent::behave()
{
	//TODO: speed and mass should come from constructor, so can come from physics component
	int speedIncrease = force / mass;
	auto a = new SpeedIncreaseAction(speedIncrease, dir);
	for(auto o : observers ){
		o->notify(a);
	}
}
