#include <unistd.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <functional>
#include <memory>
#include "gravity_component.hpp"
#include "sprite_component.hpp"
#include "pos_component.hpp"
#include "collision_component.hpp"
#include "input_component.hpp"
#include "physics_component.hpp"
#include "visuals.hpp"
#include "game.hpp"

Game::Game()
{
	visuals = std::make_unique<Visuals>();
	input = std::make_shared<Input>();
}
void Game::setupAssets()
{
	//TODO: read from file
	SDL_Texture* sheet1 = visuals->getSpritesheet("spritesheet1");

	/** player **/
	std::shared_ptr<Entity> player = std::make_shared<Entity>();
	int entityId = addEntity(player);

	SDL_Rect playerPos({0, 0, 100, 100});
	SDL_Rect playerSpriteSrc({0, 0, 32, 32});
	
	player->addBehaviorComponent(std::make_shared<GravityComponent>(player.get(), 1.0));
	player->addBehaviorComponent(std::make_shared<PhysicsComponent>(player.get()));
	player->addBehaviorComponent(std::make_shared<CollisionComponent>(player.get(), playerPos, PLAYER));
	player->addBehaviorComponent(std::make_shared<PosComponent>(player.get(), playerPos));
	auto inputComponent = std::make_shared<InputComponent>(player.get());
	player->addBehaviorComponent(inputComponent);
	input->addObserver(inputComponent);
	auto sprite = std::make_shared<SpriteComponent>(player.get(), playerPos, playerSpriteSrc, sheet1);
	player->addBehaviorComponent(sprite);
	
	visuals->addSprite(sprite);

	/** some solids **/
	SDL_Rect solidPos({0, 400, 100, 100});
	for (int i = 0; i < 10; i++){
		auto solid = std::make_shared<Entity>();
		entityId = addEntity(solid);

		SDL_Rect solidSpriteSrc({0, 0, 32, 32});
		
		auto solidSprite = std::make_shared<SpriteComponent>(solid.get(), solidPos, solidSpriteSrc, sheet1);
		solid->addBehaviorComponent(solidSprite);
		solid->addBehaviorComponent(std::make_shared<PosComponent>(solid.get(), solidPos));
		solid->addBehaviorComponent(std::make_shared<CollisionComponent>(solid.get(), solidPos, SOLID));

		visuals->addSprite(solidSprite);

		solidPos.x += 100;
	}
}

void Game::go()
{
	int countedFrames = 0;
	const int FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / FPS;
	
	setupAssets();

	keepGoing = true;


	fpsTimer.start();
	
	
	while(keepGoing){
		capTimer.start();

		keepGoing = input->process();


		for (auto e : entities){
			e->live();
		}

		visuals->render();

		float avgFps = countedFrames / ( fpsTimer.getTicks() / 1000.f );
		if( avgFps > 2000000 ){
			avgFps = 0;
		}
		//std::cout << "FPS: " << avgFps << std::endl;
		++countedFrames;
		int frameTicks = capTimer.getTicks();
		if( frameTicks < SCREEN_TICK_PER_FRAME ){
			//Wait remaining time
			SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
		}
	}
	std::cout << "DEBUG: game end" << std::endl;
}

int Game::addEntity(std::shared_ptr<Entity> entity)
{
	entities.push_back(entity);
	
	int id = entities.size() - 1;
	entity->id = id;
	return id;
}