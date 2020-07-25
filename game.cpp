#include <unistd.h>
#include <iostream>
#include "gravity_component.hpp"
#include "game.hpp"

Game::Game()
{
	Entity* e = new Entity();
	e->addBehaviorComponent(new GravityComponent(e));
	addEntity(e);
}

Game::~Game()
{
	for (auto e : entities){
		delete(e);
	}
}

void Game::go()
{
	while(true){
		for (auto e : entities){
			e->live();
		}

		sleep(1);
	}
}

entityId_t Game::addEntity(Entity* entity)
{
	entities.push_back(entity);
	return entities.size() - 1;
}
