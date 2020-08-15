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

void Entity::notify(std::weak_ptr<Action> action)
{
	switch (action.lock()->type){
		case MOVE_ENTITY:{
			auto moveEntityAction = static_pointer_cast<MoveEntityAction>(action);
			pos.x += moveEntityAction.lock()->x;
			pos.y += moveEntityAction.lock()->y;
			break;
		}
		case DUMMY:{
			std::cout << "player got dummy action" << std::endl;
			exit(1);
		}
	}
}

