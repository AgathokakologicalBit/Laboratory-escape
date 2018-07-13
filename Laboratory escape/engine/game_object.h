#pragma once

#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <typeinfo>
#include <typeindex>

#include "component.h"
#include "util/types.h"
#include "transform.h"


class GameObject final
{
private:
    using ComponentArrayType = std::vector<std::unique_ptr<Component>>;

private:
    ComponentArrayType _components;
    bool is_initialized = false;

public:
    bool is_active = true;

    std::string name;
    Layer layer;

    Transform transform;


public:
    GameObject();
    ~GameObject() = default;


protected:
    void Awake();
    void Start();
    void Update();
    void Finish();

public:
    template <typename ComponentType>
    ComponentType * GetComponent() const
    {
        const auto target_type = std::type_index(typeid(ComponentType));
        for (auto & c : _components)
            if (std::type_index(typeid(*c)) == target_type)
                return static_cast<ComponentType *>(&*c);
        return nullptr;
    }

    bool AddComponent(Component * component);


    friend class Scene;
};
