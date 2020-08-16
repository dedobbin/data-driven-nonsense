#include <SDL2/SDL.h> 
#include <memory>
#include "action.hpp"
#include "input.hpp"


std::vector<std::shared_ptr<Action>> Input::process(){
	std::vector<std::shared_ptr<Action>> actions;
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 ){
		if (e.type == SDL_QUIT){
			actions.push_back(std::make_shared<Action>(QUIT));
		} 
	}
	actions.push_back(std::make_shared<MoveEntityAction>(2, 0));
	return actions;
}
