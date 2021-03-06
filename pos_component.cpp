#include "pos_component.hpp"

PosComponent::PosComponent(Entity* owner, SDL_Rect pos)
: BehaviorComponent(owner), pos(pos)
{}

void PosComponent::behave()
{

}

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
