#include <iostream>
#include <SDL2/SDL.h> 

#include "input_component.hpp"

float speedIncrease = 1.0;
float maxRunSpeed = 10.0;
float slowdownSpeed = 0.4;

InputComponent::InputComponent(Entity* owner, float xSpeed, float ySpeed)
:BehaviorComponent(owner), xSpeed(xSpeed), ySpeed(ySpeed)
{
	for (int i = 0; i < SDL_NUM_SCANCODES; i++){
		keysDown[i] = false; 
	}
}

void InputComponent::behave()
{
	if (keysDown[SDL_SCANCODE_RIGHT]){
		if (xSpeed < maxRunSpeed){
			notifyAll(std::make_shared<SpeedIncreaseAction>(speedIncrease, 0));
		}
	} else if (xSpeed > 0){
		notifyAll(std::make_shared<SpeedIncreaseAction>(-slowdownSpeed, 0));
	} 
	if (keysDown[SDL_SCANCODE_LEFT]){
		if (xSpeed > -maxRunSpeed){
			notifyAll(std::make_shared<SpeedIncreaseAction>(-speedIncrease, 0));
		}
	} else if (xSpeed < 0){
		notifyAll(std::make_shared<SpeedIncreaseAction>(slowdownSpeed, 0));
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
			//std::cout << "DEBUG: xspeed: " << xSpeed << std::endl;
			if (setPropertyAction->propertyType == X_SPEED){
				xSpeed = setPropertyAction->floatValue;
			}
		}
	}
}