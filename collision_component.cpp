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
	std::shared_ptr<Entity> owner, 
	std::vector<std::shared_ptr<Entity>>* colliders, 
	std::unordered_map<int, collisionActionType_t>* collisionMap
)
: owner(owner), colliders(colliders), collisionMap(collisionMap)
{}

void CollisionComponent::behave()
{
	for (auto collider: *colliders){
		if (collider->id == owner->id){
			continue;
		}
		if (collision(owner->pos, collider->pos)){
			collisionActionType_t collisionType = (*collisionMap)[collider->id];
			if (collisionType != NONE){
				auto action = std::make_shared<CollisionAction>(collisionType);
				notifyAll(action);
			}
		}
	}
}

