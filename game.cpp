#include <unistd.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include "gravity_component.hpp"
#include "collision_component.hpp"
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
	player->addBehaviorComponent(new GravityComponent(player));
	player->addBehaviorComponent(new CollisionComponent(player, entities));

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
			switch (action->type){
				case MOVE_ENTITY: {
					auto moveEntityAction = (MoveEntityAction*) action;
					Entity* e = entities[moveEntityAction->entityId];
					Sprite* s = visuals->getSprite(e->getSpriteId());
					int speed = moveEntityAction->speed;
					if (moveEntityAction->dir == 0){
						s->pos.y -= speed;
					} else if (moveEntityAction->dir == 1){
						s->pos.x += speed;
					} else if (moveEntityAction->dir == 2){
						s->pos.y += speed;
					} else if (moveEntityAction->dir == 3){
						s->pos.x -= speed;
					} 
					break;
				}
				default: 
					std::cerr << "Unknown action type " << action->type << std::endl;
			}
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
	int spriteId = visuals->addSprite({srcX, srcY, srcW, srcH}, {posX, posY, posW, posH}, spritesheetStr);
	entity->setSpriteId(spriteId);
	entities.push_back(entity);
	
	int id = entities.size() - 1;
	entity->setId(id);
	return id;
}