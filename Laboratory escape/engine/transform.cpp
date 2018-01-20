#include "transform.h"

Transform::Transform(GameObject & go)
	: game_object(go)
	, position(0, 0)
	, rotation(0)
	, scale(1, 1)
{ }
