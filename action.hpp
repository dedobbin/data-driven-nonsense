#ifndef __ACTION_HPP__
#define __ACTION_HPP__

enum actionType_t
{
	SPEED_INCREASE,
	MOVE_ENTITY,
	COLLISION,
};

enum collisionActionType_t
{
	NONE, //0 should be NONE, so if collisionMap[i] returns NULL, it's seen as NONE
	SOLID,
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
		SpeedIncreaseAction(float speed, int dir);
		const float speed;
		const int dir;
};

class MoveEntityAction : public Action 
{
	public:
		MoveEntityAction(float x, float y);
		const float x;
		const float y;
};

class CollisionAction : public Action
{
	public:
		CollisionAction(collisionActionType_t collisionType);
		const collisionActionType_t collisionActionType;
};

#endif