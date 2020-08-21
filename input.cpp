#include <SDL2/SDL.h> 
#include <memory>
#include "action.hpp"
#include "input.hpp"

//TODO: dynamic
const float increaseAmount = 1.0;
const float maxRunSpeed = 3.0;

bool Input::process(){
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ){
		if (e.type == SDL_QUIT){
			return false;
		} else if (e.type == SDL_KEYDOWN){
			notifyAll(std::make_shared<KeyPressAction>(e.key.keysym.scancode, true));
		} else {
			notifyAll(std::make_shared<KeyPressAction>(e.key.keysym.scancode, false));
		}
	}
	return true;
}


void Input::notify(std::shared_ptr<Action> action)
{

}
