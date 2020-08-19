#include <iostream>
#include <memory>
#include "collision_component.hpp"
#include "entity.hpp"


bool collision(SDL_Rect A, SDL_Rect B)
{
	//thnx lazy foo
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
        
    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }
    
    if( topA >= bottomB )
    {
        return false;
    }
    
    if( rightA <= leftB )
    {
        return false;
    }
    
    if( leftA >= rightB )
    {
        return false;
    }
    
    //If none of the sides from A are outside B
    return true;
}

CollisionComponent::CollisionComponent(
	int ownerEntityId, 
	SDL_Rect pos,
	std::vector<std::shared_ptr<Entity>>* colliders, 
	std::unordered_map<int, collisionActionType_t>* collisionMap
)
: ownerEntityId(ownerEntityId), pos(pos), colliders(colliders), collisionMap(collisionMap)
{}

void CollisionComponent::behave()
{
	for (auto collider: *colliders){
		if (collider->id == ownerEntityId){
			continue;
		}
		std::cout << "DEBUG: player pos in collision component" << pos.x << "," << pos.y << std::endl;
		if (collision(*pos, collider.pos)){
			collisionActionType_t collisionType = (*collisionMap)[collider->id];
			if (collisionType != NONE){
				auto action = std::make_shared<CollisionAction>(collisionType);
				notifyAll(action);
			}
		}
	}
}

void CollisionComponent::notify(std::shared_ptr<Action> action)
{
	switch (action->type){
		case MOVE_ENTITY:{
			auto moveEntityAction = std::static_pointer_cast<MoveEntityAction>(action);
			pos.x += moveEntityAction->x;
			pos.y += moveEntityAction->y;
			break;
		}
	}
}