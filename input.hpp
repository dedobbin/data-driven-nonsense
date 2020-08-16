#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "observer.hpp"

class Input : public Observer
{
	public:
		void process();	
};

#endif