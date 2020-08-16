#include <SDL2/SDL.h> 
#include <memory>
#include "action.hpp"
#include "input.hpp"


bool Input::process(){
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ){
		if (e.type == SDL_QUIT){
			return false;
		} 
	}
	notifyAll(std::make_shared<MoveEntityAction>(2, 0));
	return true;
}


void Input::notify(std::shared_ptr<Action> action)
{}
