#include "input_component.hpp"

InputComponent::InputComponent(Entity* owner, std::shared_ptr<Input> input)
:BehaviorComponent(owner)
{
	input->addObserver(input);
}

void InputComponent::behave()
{}