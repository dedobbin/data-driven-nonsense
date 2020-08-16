#include <SDL2/SDL.h> 
#include "input.hpp"

void Input::process(){
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ){
		if (e.type == SDL_QUIT){
			notifyAll(std::make_shared<Action>(QUIT));
		}
	}
}