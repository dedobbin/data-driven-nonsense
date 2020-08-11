#include <memory>
#include <iostream>
#include "behavior_component.hpp"

void BehaviorComponent::notify(std::shared_ptr<Action>)
{	
	std::cerr << "Called class componenent notify" << std::endl;
}

void DummyComponent::notify(std::shared_ptr<Action> action)
{
	std::cerr << "dummy component got notified, broadcast dummy action" << std::endl;
	notifyAll(std::make_shared<Action>(DUMMY));
}

void DummyComponent::behave()
{

}