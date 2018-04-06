#include "collider.h"
#include "../engine.h"

void Collider::Awake()
{ }

void Collider::Start()
{
    this->rigidbody = object->GetComponent<Rigidbody>();
}

void Collider::Update()
{
    static PhysicsEngine & engine = Engine::Get().physics_engine;
    engine.Push(this, this->rigidbody);
}

void Collider::Finish()
{ }
