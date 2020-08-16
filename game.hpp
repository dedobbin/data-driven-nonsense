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
		int addEntity(std::shared_ptr<Entity> entity, 
			int srcX, int srcY, int srcW, int srcH,
			int posX, int posY, int posW, int posH,
			std::string spritesheetStr
		);
	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::unordered_map<int, collisionActionType_t> collisionMap; //entity id and collisionType
		std::unique_ptr<Input> input;
		std::unique_ptr<Visuals, std::default_delete<Visuals>> visuals;

		bool initSDL();
		std::vector<std::shared_ptr<BehaviorComponent>> componentPool; //keep alive
		LazyFooTimer capTimer;
		LazyFooTimer fpsTimer;
		bool keepGoing = true;
};

#endif