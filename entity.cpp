#include <iostream>
#include "behavior_component.hpp"
#include "entity.hpp"

void Entity::live()
{
	for (auto component : behaviorComponents){
		component->behave();
	}
}

int Entity::addBehaviorComponent(std::shared_ptr<BehaviorComponent> component)
{
	behaviorComponents.push_back(component);
	return behaviorComponents.size() - 1;
}

void Entity::notify(std::shared_ptr<Action> action)
{
	switch (action->type){
		case MOVE_ENTITY:{
			auto moveEntityAction = std::static_pointer_cast<MoveEntityAction>(action);
			pos.x += moveEntityAction->x;
			pos.y += moveEntityAction->y;
			break;
		}
	}
}