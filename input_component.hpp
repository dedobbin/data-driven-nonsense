#ifndef __INPUT_COMPONENT_HPP__
#define __INPUT_COMPONENT_HPP__

#include "input.hpp"
#include "behavior_component.hpp"

class InputComponent : public BehaviorComponent
{
	public:
		InputComponent(Entity* owner, std::shared_ptr<Input> input);
		void behave();
};

#endif