#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include <unordered_map>
#include "visuals.hpp" 
#include "action.hpp"
#include "entity.hpp"
#include "sdl_utils.hpp"

class Game
{
	public:
		Game();
		~Game();
		void setupAssets();
		void go();
		int addEntity(Entity* entity, 
			int srcX, int srcY, int srcW, int srcH,
			int posX, int posY, int posW, int posH,
			std::string spritesheetStr
		);
	private:
		std::vector<Entity*> entities;
		std::unordered_map<int, collisionActionType_t> collisionMap; //entity id and collisionType
		bool initSDL();
		Visuals* visuals;

		LazyFooTimer capTimer;
		LazyFooTimer fpsTimer;
};

#endif