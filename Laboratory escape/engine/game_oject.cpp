#include "game_object.h"

GameObject::GameObject()
    : name()
    , layer(0)
    , transform(*this)
{ }

void GameObject::Awake()
{ }

void GameObject::Start()
{ }

void GameObject::Update()
{
    for (auto & c : _components)
    {
        if (!c->is_active) continue;

        if (!c->is_initialized)
        {
            c->Start();
            c->is_initialized = true;
        }
        c->Update();
    }
}

void GameObject::Finish()
{
    for (auto & c : _components)
        c->Finish();
}

bool GameObject::AddComponent(Component * component)
{
    if (!component) return false;

    _components.emplace_back(component);

    component->object = this;
    component->Awake();

    return true;
}
