#include "entity.hpp"
#include "behavior_component.hpp"

BehaviorComponent::BehaviorComponent(Entity* owner)
: owner(owner)
{}