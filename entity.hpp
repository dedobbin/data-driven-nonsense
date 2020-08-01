#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <vector>
#include <SDL2/SDL.h>
#include "action.hpp"
#include "behavior_component.hpp"
#include "entity.hpp"


class Entity
{
	public:
		~Entity();
		void live(std::vector<Action*>& triggeredActions);
		int addBehaviorComponent(BehaviorComponent* component);
		//TODO: i dont think i need getters and setters for this..
		int getId();
		void setId(int id);
		int getSpriteId();
		void setSpriteId(int id);
		SDL_Rect pos;
	private:
		std::vector<BehaviorComponent*> behaviorComponents;	
		int spriteId = -1;
		int id = -1;
};

#endif