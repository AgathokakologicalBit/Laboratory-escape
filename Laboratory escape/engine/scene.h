#pragma once

#include <cassert>
#include <string>
#include <memory>
#include "util/types.h"
#include "util/state.h"
#include "game_object.h"


class Scene: public State
{
public:
    SceneId id;
    std::string name;

    std::vector<std::shared_ptr<GameObject>> objects;

public:
    Scene() = default;
    ~Scene() = default;


public:
    virtual void Start()
    { };
    virtual void Pause()
    { };
    virtual void Resume()
    { };
    virtual void Stop()
    { };

    virtual void Update()
    {
        for (auto obj : objects)
        {
            if (!obj->is_active) continue;

            if (!obj->is_initialized)
            {
                obj->Start();
                obj->is_initialized = true;
            }
            obj->Update();
        }
    };


public:
    template <typename... Ct>
    std::shared_ptr<GameObject> SpawnObject()
    {
        auto obj = std::make_shared<GameObject>();

        bool res = ((obj->AddComponent(new Ct)) & ... & 1);
        assert(res);

        objects.push_back(obj);
        return obj;
    }
};
