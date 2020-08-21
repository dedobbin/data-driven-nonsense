#ifndef __ACTION_HPP__
#define __ACTION_HPP__

//TODO: put actions in their own files

enum actionType_t
{
	SPEED_INCREASE,
	MOVE_ENTITY,
	COLLISION,
	QUIT,
	KEY_PRESS,
	SET_PROPERTY
};

enum collisionType_t
{
	NONE, //0 should be NONE, so if collisionMap[i] returns NULL, it's seen as NONE, although i think this got refactored into oblivion
	SOLID,
	PLAYER,
};

enum propertyType_t
{
	X_SPEED,
	Y_SPEED
};

class Action 
{
	public:
		Action(actionType_t type);
		~Action();
		const actionType_t type;
};

class SetPropertyAction : public Action
{
	public:
		SetPropertyAction(propertyType_t propertyType, float floatValue);
		const propertyType_t propertyType;
		const float floatValue;	
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
		CollisionAction(collisionType_t collisionType);
		const collisionType_t collisionType;
};

class KeyPressAction : public Action
{
	public:
		KeyPressAction(int scanCode, bool down); //true = down, false = released
		const int scanCode;
		const bool down;
};

#endif