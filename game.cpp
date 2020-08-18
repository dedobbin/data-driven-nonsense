#include <unistd.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <functional>
#include <memory>
#include "gravity_component.hpp"
#include "collision_component.hpp"
#include "physics_component.hpp"
#include "visuals.hpp"
#include "game.hpp"

Game::Game()
{
	visuals = std::make_unique<Visuals>();
}
void Game::setupAssets()
{
	//TODO: read from file
	/** player **/
	std::shared_ptr<Entity> player = std::make_shared<Entity>();
	int entityId = addEntity(player, 0, 0, 32, 32, 100, 0, 100, 100, "spritesheet1.png");
	player->addBehaviorComponent(std::make_shared<GravityComponent>(1.0));
	player->addBehaviorComponent(std::make_shared<PhysicsComponent>());
	player->addBehaviorComponent(std::make_shared<CollisionComponent>(player->id, &player->pos, &entities, &collisionMap));


	/** some solids **/
	// auto solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 100, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;

	// solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 200, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;

	// solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 300, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;



	/** player **/
	// std::shared_ptr<Entity> player = std::make_shared<Entity>();
	// int entityId = addEntity(player, 0, 0, 32, 32, 100, 0, 100, 100, "spritesheet1.png");
	// float playerMass = 1.0;

	// auto gravity = std::make_shared<GravityComponent>(playerMass);
	// componentPool.push_back(gravity);
	// player->addBehaviorComponent(gravity);

	// auto physics = std::make_shared<PhysicsComponent>();
	// componentPool.push_back(physics);
	// gravity->addObserver(physics);
	// player->addBehaviorComponent(physics);
	// physics->addObserver(player);

	// auto collision = std::make_shared<CollisionComponent>(player, &entities, &collisionMap);
	// componentPool.push_back(collision);
	// player->addBehaviorComponent(collision);
	// int debugIndex = collision->addObserver(physics);

	// //needs to listen to controls
	// input->addObserver(physics);

	// // collision->removeObserver(debugIndex);

	// /** some solid **/
	// auto solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 100, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;

	// solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 200, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;

	// solid = std::make_shared<Entity>();
	// entityId = addEntity(solid, 0, 0, 32, 32, 300, 400, 100, 100, "spritesheet1.png");
	// collisionMap[entityId] = SOLID;
}

void Game::go()
{
	int countedFrames = 0;
	const int FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / FPS;
	
	input = std::make_unique<Input>();
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

int Game::addEntity(std::shared_ptr<Entity> entity, 
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