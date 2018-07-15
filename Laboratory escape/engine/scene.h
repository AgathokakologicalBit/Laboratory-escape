#pragma once

#include <cassert>
#include <string>
#include <memory>

#include "util/types.h"
#include "util/state.h"
#include "game_object.h"


namespace
{
    struct SpawningObject
    {
    private:
        std::vector<std::shared_ptr<GameObject>> &objectsRef;
        std::shared_ptr<GameObject> spawningObject;
        bool success;

    private:
        SpawningObject(std::vector<std::shared_ptr<GameObject>> & objects)
            : objectsRef(objects)
            , spawningObject(std::make_shared<GameObject>())
            , success(true)
        { }

    public:
        template <typename Ct, typename... Pts>
        SpawningObject & with(Pts... params)
        {
            success &= spawningObject->AddComponent(new Ct(params...));
            return *this;
        }

        std::shared_ptr<GameObject> Spawn()
        {
            objectsRef.push_back(spawningObject);
            assert(success);
            return spawningObject;
        }

        friend class Scene;
    };
}

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
    SpawningObject MakeObject()
    {
        return SpawningObject(objects);
    }
};
