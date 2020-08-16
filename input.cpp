#include <SDL2/SDL.h> 
#include <memory>
#include "action.hpp"
#include "input.hpp"

int speed = 1;

bool Input::process(){
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ){
		if (e.type == SDL_QUIT){
			return false;
		} else if (e.type == SDL_KEYDOWN){
			std::shared_ptr<Action> action;
			
			switch(e.key.keysym.sym){
                case SDLK_LEFT:{
					speed++;
					notifyAll(std::make_shared<MoveEntityAction>(speed *-1, 0));
					break;
				}
				case SDLK_RIGHT:{
					speed ++;
					notifyAll(std::make_shared<MoveEntityAction>(speed, 0));
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
{}
