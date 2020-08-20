#ifndef __POS_COMPONENT_HPP__
#define __POS_COMPONENT_HPP__

#include <SDL2/SDL.h> 
#include "behavior_component.hpp"

class PosComponent : public BehaviorComponent
{
	public:
		PosComponent(Entity* owner, SDL_Rect pos);
		void behave();
		void notify(std::shared_ptr<Action> action);

	private:
		SDL_Rect pos;
};

#endif