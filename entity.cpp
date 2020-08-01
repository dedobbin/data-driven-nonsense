#include "behavior_component.hpp"
#include "entity.hpp"

Entity::~Entity()
{
	for (auto component : behaviorComponents){
		delete(component);
	}
}

void Entity::live(std::vector<Action*>& triggeredActions)
{
	for (auto component : behaviorComponents){
		component->behave(triggeredActions);
	}
}

int Entity::addBehaviorComponent(BehaviorComponent* component)
{
	behaviorComponents.push_back(component);
	return behaviorComponents.size() - 1;
}

int Entity::getId()
{
	return id;
}

void Entity::setId(int val)
{
	id = val;
}

int Entity::getSpriteId()
{
	return spriteId;
}

void Entity::setSpriteId(int val)
{
	spriteId = val;
}