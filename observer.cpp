#include <iostream>
#include "observer.hpp"


int Observer::addObserver(std::shared_ptr<Observer> observer)
{
	int index = observers.size();
	observers.push_back(observer);
	return index;
}

void Observer::removeObserver(int index)
{
	observers.erase(observers.begin() + index);
}

void Observer::notify(std::weak_ptr<Action> action)
{
	std::cerr << "base BehaviorComponent got notified: " << action.lock()->type << std::endl;
}

void Observer::notifyAll(std::weak_ptr<Action> action)
{
	for (auto o : observers){
		
		o->notify(action);
	}
}