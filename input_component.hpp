#ifndef __INPUT_COMPONENT_HPP__
#define __INPUT_COMPONENT_HPP__

#include "input.hpp"
#include "behavior_component.hpp"

class InputComponent : public BehaviorComponent
{
	public:
		InputComponent(Entity* owner);
		void behave();
		void notify(std::shared_ptr<Action> action);
	private:
		std::unordered_map<int, bool> keysDown;//scancode and false = up, true = down
};

#endif