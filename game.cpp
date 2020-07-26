#include <unistd.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "gravity_component.hpp"
#include "visuals.hpp"
#include "game.hpp"

Game::Game()
{
	visuals = new Visuals();

	Entity* e = new Entity();
	e->addBehaviorComponent(new GravityComponent(e));
	//TODO: get sprite position from file
	addEntity(e, 0, 0, 32, 32, 0, 0, 100, 100, "spritesheet1.png");
}

Game::~Game()
{
	for (auto e : entities){
		delete(e);
	}
	delete(visuals);
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

		for (auto action : triggeredActions){
			delete(action);
		} 
		triggeredActions = {};

		SDL_Event e;
		while( SDL_PollEvent( &e ) != 0 ){
			if (e.type == SDL_QUIT){
				keepGoing = false;
			}
		}

		for (auto e : entities){
			e->live(triggeredActions);
		}

		for (auto action : triggeredActions){
			//TODO: process actions
		}

		visuals->render();

		float avgFps = countedFrames / ( fpsTimer.getTicks() / 1000.f );
		if( avgFps > 2000000 ){
			avgFps = 0;
		}
		std::cout << "FPS: " << avgFps << std::endl;
		++countedFrames;
		int frameTicks = capTimer.getTicks();
		if( frameTicks < SCREEN_TICK_PER_FRAME ){
			//Wait remaining time
			SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
		}
	}
}

entityId_t Game::addEntity(Entity* entity, 
	int srcX, int srcY, int srcW, int srcH,
	int posX, int posY, int posW, int posH,
	std::string spritesheetStr
)
{
	int spriteId = visuals->addSprite({srcX, srcY, srcW, srcH}, {posX, posY, posW, posH}, spritesheetStr);
	entities.push_back(entity);
	return entities.size() - 1;
}