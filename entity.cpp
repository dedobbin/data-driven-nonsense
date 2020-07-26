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
		component->behave();
	}
}

componentId_t Entity::addBehaviorComponent(BehaviorComponent* component)
{
	behaviorComponents.push_back(component);
	return behaviorComponents.size() - 1;
}
