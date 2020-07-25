#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include "entity.hpp"

class Game
{
	public:
		Game();
		~Game();
		void go();
		entityId_t addEntity(Entity* e);
	private:
		std::vector<Entity*> entities;
};

#endif