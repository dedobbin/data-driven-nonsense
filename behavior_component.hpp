#ifndef __BEHAVIOR_COMPONENT__
#define __BEHAVIOR_COMPONENT__

//Forward declaration because circ dep
class Entity;

typedef int componentId_t; 

class BehaviorComponent
{
	public:
		BehaviorComponent(Entity* owner);
		virtual void behave() = 0;
	private:
		Entity* owner;
};

#endif