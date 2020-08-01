#include "action.hpp"

Action::Action(actionType_t type)
: type(type)
{}

MoveEntityAction::MoveEntityAction(int entityId, int speed, int dir)
: Action (MOVE_ENTITY), entityId(entityId), speed(speed), dir(dir)
{}