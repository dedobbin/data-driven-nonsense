#ifndef __ACTION_HPP__
#define __ACTION_HPP__

enum actionType_t
{
	MOVE_ENTITY
};

class Action 
{
	public:
		Action(actionType_t type);
		const actionType_t type;
};

class MoveEntityAction : public Action
{
	public:
		MoveEntityAction(int entityType, int speed, int dir);
		const int speed;
		const int dir;
		const int entityId;
};

#endif