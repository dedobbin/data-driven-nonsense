#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <memory>
#include <vector>
#include "action.hpp"

class Observer;

class Observer 
{
	public:
		int addObserver(std::shared_ptr<Observer> observer);
		void removeObserver(int id);
		virtual void notify(std::shared_ptr<Action> action) = 0;
	protected:
		std::vector<std::shared_ptr<Observer>> observers;
		void notifyAll(std::shared_ptr<Action> action);
};

#endif