#include <memory>
#include <iostream>
#include "behavior_component.hpp"

void BehaviorComponent::notify(std::shared_ptr<Action>)
{	
	std::cerr << "Called class componenent notify" << std::endl;
}