#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include <vector>
#include "action.hpp"
#include "observer.hpp"

class Entity;

class BehaviorComponent : public Observer
{
	public:
		virtual void behave() = 0;
		int addObserver(Observer* observer);
		void removeObserver(int id);
		virtual void notify(Action* action);
	protected:
		std::vector<Observer*> observers;
};

#endif