#include "pos_component.hpp"

PosComponent::PosComponent(SDL_Rect pos)
: pos(pos)
{}

void PosComponent::notify(std::shared_ptr<Action> action)
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
