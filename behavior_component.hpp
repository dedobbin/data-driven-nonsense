#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include "observer.hpp"

class Entity;

class BehaviorComponent : public Observer
{
	public:
		BehaviorComponent(Entity* owner);
		~BehaviorComponent();
		void notify(std::shared_ptr<Action> action);
		virtual void behave() = 0;
	protected:
		const Entity* const owner;
};

#endif