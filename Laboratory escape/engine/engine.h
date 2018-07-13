#pragma once

#include "util/time.h"
#include "scene_manager.h"
#include "rendering_engine.h"
#include "physics_engine.h"


class Engine
{
public:
    Time time;
    SceneManager scene_manager;

    RenderingEngine rendering_engine;
    PhysicsEngine physics_engine;


public:
    Engine();
    ~Engine() = default;

    static Engine & Get()
    {
        static auto instance = new Engine;
        return *instance;
    }


public:
    int Start();
    bool Update();
    void Stop();
};
