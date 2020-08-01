#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include <vector>
#include "action.hpp"

typedef int componentId_t; 

class BehaviorComponent
{
	public:
		BehaviorComponent(int ownerEntityId);
		virtual void behave(std::vector<Action*> &triggeredAction) = 0;
		const int ownerEntityId;
};

#endif