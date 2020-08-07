#include "behavior_component.hpp"
#include <iostream>

int BehaviorComponent::addObserver(Observer* observer)
{
	int id = observers.size();
	observer->id = id;
	observers.push_back(observer);
	return id;
}

void BehaviorComponent::notify(Action* action)
{
	std::cerr << "base BehaviorComponent got notified: " << action->type << std::endl;
}

void BehaviorComponent::notifyAll(Action* action)
{
	for (auto o : observers){
		o->notify(action);
	}
}