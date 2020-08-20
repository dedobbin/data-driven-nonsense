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

CollisionComponent::CollisionComponent(Entity* owner, SDL_Rect pos, collisionType_t type)
:pos(pos), BehaviorComponent(owner)
{
	CollisionWrapper wrapper({this, type});
	colMap[owner->id] = wrapper;
}

CollisionComponent::~CollisionComponent()
{
	colMap.erase(owner->id);
}

void CollisionComponent::behave()
{

}

void CollisionComponent::notify(std::shared_ptr<Action> action)
{
	if (action->type == MOVE_ENTITY){
		auto moveEntityAction = std::static_pointer_cast<MoveEntityAction>(action);
		//TODO: check collision
		pos.x += moveEntityAction->x;
		pos.y += moveEntityAction->y;
		for(auto iter = colMap.begin(); iter != colMap.end(); ++iter){
			if (iter->first == owner->id){
				continue;
			}
			//std::cout << "DEBUG" << pos.x << "," << pos.y << " - " << iter->second.col->pos.x << "," << iter->second.col->pos.y << std::endl;
			if (collision(pos, iter->second.col->pos)){
				//std::cout << "DEBUG: COLLISION" << std::endl;
				notifyAll(std::make_shared<CollisionAction>(iter->second.type));
			}
		}
	}
}

std::unordered_map<int, CollisionWrapper> CollisionComponent::colMap = {};
