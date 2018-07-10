#pragma once

#include "component.h"

class Behavior: public Component
{
protected:
    virtual void Awake() {};
    virtual void Start() {};
    virtual void Update() {};
    virtual void Finish() {};


    friend class GameObject;
};
