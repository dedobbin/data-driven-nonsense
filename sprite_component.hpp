#ifndef __SPRITE_COMPONENT_HPP__
#define __SPRITE_COMPONENT_HPP__

#include <SDL2/SDL.h> 
#include "behavior_component.hpp"


class SpriteComponent : public BehaviorComponent
{
	public:
		SpriteComponent(Entity* owner, SDL_Rect pos, SDL_Rect src, SDL_Texture* texture);
		void notify(std::shared_ptr<Action> action);
		void behave();
		SDL_Rect src;
		SDL_Texture* spritesheet = NULL;
		SDL_Rect pos;
};

#endif