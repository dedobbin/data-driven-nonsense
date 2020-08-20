#include <memory>
#include <iostream>
#include "entity.hpp"
#include "behavior_component.hpp"

BehaviorComponent::BehaviorComponent(Entity* owner)
: owner(owner)
{}

BehaviorComponent::~BehaviorComponent()
{
	std::cout << "DEBUG: BehaviorComponent deconstructor called" << std::endl; 
}

void BehaviorComponent::notify(std::shared_ptr<Action>)
{	
	//std::cerr << "Called Component notify" << std::endl;
}