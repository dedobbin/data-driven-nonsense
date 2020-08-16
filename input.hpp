#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <vector>

class Input
{
	public:
	std::vector<std::shared_ptr<Action>> process();
};

#endif