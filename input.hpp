#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <vector>
#include "observer.hpp"

class Input : public Observer 
{
	public:
		bool process();
		void notify(std::shared_ptr<Action> action);
	private:
		float speed = 0.0;
};

#endif