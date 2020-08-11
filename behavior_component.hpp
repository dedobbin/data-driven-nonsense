#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include "observer.hpp"

class BehaviorComponent : public Observer
{
	public:
		void notify(std::shared_ptr<Action> action);
		virtual void behave() = 0;
};

#endif