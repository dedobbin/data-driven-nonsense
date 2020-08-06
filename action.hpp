#ifndef __ACTION_HPP__
#define __ACTION_HPP__

enum actionType_t
{
	SPEED_INCREASE,
	MOVE_ENTITY,

};

class Action 
{
	public:
		Action(actionType_t type);
		const actionType_t type;
};

class SpeedIncreaseAction : public Action
{
	public:
		SpeedIncreaseAction(int speed, int dir);
		const int speed;
		const int dir;
};

class MoveEntityAction : public Action 
{
	public:
		MoveEntityAction(float x, float y);
		const float x;
		const float y;
};

#endif