#include <unistd.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "gravity_component.hpp"
#include "collision_component.hpp"
#include "physics_component.hpp"
#include "visuals.hpp"
#include "game.hpp"

Game::Game()
{
	visuals = new Visuals();
	setupAssets();
}

Game::~Game()
{
	for (auto e : entities){
		delete(e);
	}
	delete(visuals);
}

void Game::setupAssets()
{
	//TODO: read from file

	Entity* player = new Entity();
	int entityId = addEntity(player, 0, 0, 32, 32, 100, 0, 100, 100, "spritesheet1.png");
	
	auto gravity = new GravityComponent(player);
	player->addBehaviorComponent(gravity);

	auto physics = new PhysicsComponent(player);
	gravity->addObserver(physics);
	player->addBehaviorComponent(gravity);

	auto collision = new CollisionComponent(player, &entities);
	physics->addObserver(collision);
	player->addBehaviorComponent(collision);

	Entity* solid = new Entity();
	entityId = addEntity(solid, 0, 0, 32, 32, 100, 400, 100, 100, "spritesheet1.png");
}

void Game::go()
{
	int countedFrames = 0;
	const int FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / FPS;
	bool keepGoing = true;

	fpsTimer.start();
	
	while(keepGoing){
		capTimer.start();

		SDL_Event e;
		while( SDL_PollEvent( &e ) != 0 ){
			if (e.type == SDL_QUIT){
				keepGoing = false;
			}
		}

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
}

int Game::addEntity(Entity* entity, 
	int srcX, int srcY, int srcW, int srcH,
	int posX, int posY, int posW, int posH,
	std::string spritesheetStr
)
{
	entity->pos.w = posW;
	entity->pos.h = posH;
	entity->pos.x = posX;
	entity->pos.y = posY;

	int spriteId = visuals->addSprite({srcX, srcY, srcW, srcH}, &entity->pos, spritesheetStr);
	entity->spriteId = spriteId;
	entities.push_back(entity);
	
	int id = entities.size() - 1;
	entity->id = id;
	return id;
}