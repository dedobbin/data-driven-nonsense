#include <memory>
#include <iostream>
#include "behavior_component.hpp"

BehaviorComponent::~BehaviorComponent()
{
	//std::cout << "DEBUG: BehaviorComponent deconstructor called" << std::endl; 
}

void BehaviorComponent::notify(std::weak_ptr<Action>)
{	
	std::cerr << "Called class componenent notify" << std::endl;
}