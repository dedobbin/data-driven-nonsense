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
			switch(e.key.keysym.sym){
                case SDLK_LEFT:{
					notifyAll(std::make_shared<SpeedIncreaseAction>(increaseAmount, 0));
					break;
				}
				case SDLK_RIGHT:{
					notifyAll(std::make_shared<SpeedIncreaseAction>(increaseAmount, 0));
					break;
				}
				default:
					break;
			}
		}
	}
	return true;
}


void Input::notify(std::shared_ptr<Action> action)
{

}
