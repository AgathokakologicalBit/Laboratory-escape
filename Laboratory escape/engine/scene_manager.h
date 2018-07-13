#pragma once

#include "util/types.h"
#include "util/state_machine.h"
#include "scene.h"


class SceneManager final: public StateMachine<Scene>
{
public:
    SceneManager() = default;
    ~SceneManager() = default;


public:
    void Load(Scene * scene, StatePushMode mode)
    {
        Push(scene, mode);
    }
};
