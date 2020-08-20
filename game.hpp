#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <vector>
#include <unordered_map>
#include <memory>
#include "visuals.hpp" 
#include "action.hpp"
#include "entity.hpp"
#include "input.hpp"
#include "sdl_utils.hpp"

class Game
{
	public:
		Game();
		void setupAssets();
		void go();
		int addEntity(std::shared_ptr<Entity> entity);
	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<Input> input;
		std::unique_ptr<Visuals> visuals;

		bool initSDL();
		LazyFooTimer capTimer;
		LazyFooTimer fpsTimer;
		bool keepGoing = true;
};

#endif