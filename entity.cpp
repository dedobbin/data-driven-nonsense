#include <iostream>
#include "helpers.hpp"
#include "behavior_component.hpp"
#include "entity.hpp"

Entity::~Entity()
{
	//std::cout << "DEBUG: Entity deconstructor called" << std::endl; 
}

void Entity::live()
{
	for (auto w : behaviorComponents){
		auto component = w.lock();
		component->behave();
	}
}

int Entity::addBehaviorComponent(std::shared_ptr<BehaviorComponent> component)
{
	behaviorComponents.push_back(component);
	return behaviorComponents.size() - 1;
}

void Entity::removeBehaviorcomponent(int index)
{
	behaviorComponents.erase(behaviorComponents.begin() + index);
}

void Entity::notify(std::shared_ptr<Action> action)
{
	switch (action->type){
		case MOVE_ENTITY:{
			auto moveEntityAction = static_pointer_cast<MoveEntityAction>(action);
			pos.x += moveEntityAction->x;
			pos.y += moveEntityAction->y;
			break;
		}
	}
}

