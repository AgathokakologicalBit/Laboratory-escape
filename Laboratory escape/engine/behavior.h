#pragma once

#include "component.h"

class Behavior : public Component
{
protected:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Finish() = 0;


	friend class GameObject;
};
