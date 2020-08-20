#include "sprite_component.hpp"

SpriteComponent::SpriteComponent(Entity* owner, SDL_Rect pos, SDL_Rect src, SDL_Texture* texture)
: BehaviorComponent(owner), src(src), pos(pos), spritesheet(texture)
{
	
}

void SpriteComponent::behave()
{}

void SpriteComponent::notify(std::shared_ptr<Action> action)
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