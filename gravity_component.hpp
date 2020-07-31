#ifndef __gravity_component_HPP__
#define __PHSYSICS_COMPONENT_HPP__

#include "behavior_component.hpp"

class gravityComponentponent : public BehaviorComponent
{
	public:
		gravityComponentponent(int ownerEntityId);
		void behave(std::vector<Action*>& actions);
	private:
		float acceleration = 0;
		float force = 0.5;	//force of gravity
		float mass = 1;
		int dir = 2;
};

#endif