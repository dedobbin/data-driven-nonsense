#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <unordered_map>
#include "observer.hpp"

class Input : public Observer 
{
	public:
		bool process();
		void notify(std::shared_ptr<Action> action);
};

#endif