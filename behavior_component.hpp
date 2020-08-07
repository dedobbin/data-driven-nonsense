#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

#include <vector>
#include <memory>
#include "action.hpp"
#include "observer.hpp"

class BehaviorComponent : public Observer
{
	public:
		virtual void behave() = 0;
		int addObserver(std::shared_ptr<Observer> observer);
		void removeObserver(int id);
		virtual void notify(std::shared_ptr<Action> action);
	protected:
		std::vector<std::shared_ptr<Observer>> observers;
		void notifyAll(std::shared_ptr<Action> action);

};

#endif