#include <iostream>
#include <SDL2/SDL.h> 

#include "input_component.hpp"

float speedIncrease = 1.0;
float maxRunSpeed = 3.0;

InputComponent::InputComponent(Entity* owner)
:BehaviorComponent(owner)
{
	for (int i = 0; i < SDL_NUM_SCANCODES; i++){
		keysDown[i] = false; 
	}
}

void InputComponent::behave()
{
	if (keysDown[SDL_SCANCODE_RIGHT]){
		notifyAll(std::make_shared<SpeedIncreaseAction>(speedIncrease, 0));
	}
}

void InputComponent::notify(std::shared_ptr<Action> action)
{
	switch(action->type){
		case KEY_PRESS: {
			auto keyPressAction = std::static_pointer_cast<KeyPressAction>(action);
			//std::cout << "DEBUG: InputComponent got key press" << std::endl;
			keysDown[keyPressAction->scanCode] = keyPressAction->down;
		}
		case SET_PROPERTY: {
			auto setPropertyAction = std::static_pointer_cast<SetPropertyAction>(action);
			if (setPropertyAction->type == X_SPEED){
				xSpeed = setPropertyAction->value;
				std::cout << "DEBUG: x speed: " << xSpeed << std::endl;
			}
		}
	}
}