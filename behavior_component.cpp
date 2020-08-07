#include <memory>
#include <iostream>
#include "behavior_component.hpp"

int BehaviorComponent::addObserver(std::shared_ptr<Observer> observer)
{
	int id = observers.size();
	observer->id = id;
	observers.push_back(observer);
	return id;
}

void BehaviorComponent::notify(std::shared_ptr<Action> action)
{
	std::cerr << "base BehaviorComponent got notified: " << action->type << std::endl;
}

void BehaviorComponent::notifyAll(std::shared_ptr<Action> action)
{
	for (auto o : observers){
		o->notify(action);
	}
}