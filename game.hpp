#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include "visuals.hpp" 
#include "action.hpp"
#include "entity.hpp"
#include "sdl_utils.hpp"

class Game
{
	public:
		Game();
		~Game();
		void go();
		entityId_t addEntity(Entity* entity, 
			int srcX, int srcY, int srcW, int srcH,
			int posX, int posY, int posW, int posH,
			std::string spritesheetStr
		);
	private:
		std::vector<Entity*> entities;
		bool initSDL();
		Visuals* visuals;
		std::vector<Action*> triggeredActions;

		LazyFooTimer capTimer;
		LazyFooTimer fpsTimer;
};

#endif