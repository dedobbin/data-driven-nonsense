#ifndef __gravity_component_HPP__
#define __PHSYSICS_COMPONENT_HPP__

#include "behavior_component.hpp"

class GravityComponent : public BehaviorComponent
{
	public:
		GravityComponent(float mass);
		void behave();
	private:
		float force = 0.5;	//force of gravity
		const float mass;
		int dir = 1;
};

#endif