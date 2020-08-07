#include <memory>
#include <iostream>
#include "behavior_component.hpp"

int BehaviorComponent::addObserver(std::shared_ptr<Observer> observer)
{
	int index = observers.size();
	observers.push_back(observer);
	return index;
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