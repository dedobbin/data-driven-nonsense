#ifndef __INPUT_COMPONENT_HPP__
#define __INPUT_COMPONENT_HPP__

#include "input.hpp"
#include "behavior_component.hpp"

class InputComponent : public BehaviorComponent
{
	public:
		InputComponent(Entity* owner, float xSpeed, float ySpeed);
		void behave();
		void notify(std::shared_ptr<Action> action);
	private:
		std::unordered_map<int, bool> keysDown;//scancode and false = up, true = down
		float xSpeed = 0;
		float ySpeed = 0;
};

#endif