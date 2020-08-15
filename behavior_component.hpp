#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include "observer.hpp"

class BehaviorComponent : public Observer
{
	public:
		~BehaviorComponent();
		void notify(std::weak_ptr<Action> action);
		virtual void behave() = 0;
};

#endif