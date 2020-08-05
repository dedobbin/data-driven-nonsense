#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include "action.hpp"

class Observer 
{
	public:
		int id;
		virtual void notify(Action* a) = 0;
};

#endif