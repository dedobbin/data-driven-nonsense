#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <memory>
#include "action.hpp"

class Observer 
{
	public:
		virtual void notify(std::shared_ptr<Action> a) = 0;
};

#endif