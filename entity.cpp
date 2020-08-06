#include <iostream>
#include "behavior_component.hpp"
#include "entity.hpp"

Entity::~Entity()
{
	for (auto component : behaviorComponents){
		delete(component);
	}
}

void Entity::live()
{
	for (auto component : behaviorComponents){
		component->behave();
	}
}

int Entity::addBehaviorComponent(BehaviorComponent* component)
{
	behaviorComponents.push_back(component);
	return behaviorComponents.size() - 1;
}

void Entity::notify(Action* action)
{
	switch (action->type){
		case MOVE_ENTITY:{
			auto moveEntityAction = (MoveEntityAction*)action;
			pos.x += moveEntityAction->x;
			pos.y += moveEntityAction->y;
			break;
		}
	}
}