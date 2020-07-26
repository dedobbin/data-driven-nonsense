#ifndef __ACTION_HPP__
#define __ACTION_HPP__

enum actionType_t
{
	PLACEHOLDER
};

class Action 
{
	public:
		Action(actionType_t type);
		const actionType_t type;
};

#endif