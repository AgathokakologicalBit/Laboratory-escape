#include "physics_engine.h"

#ifdef _DEBUG
#include <iostream>
#include <exception>
#endif

void PhysicsEngine::Update()
{
#ifdef _DEBUG
    std::cout << "Physical bodies: " << this->bodies.size() << '\n';
#endif
    this->bodies.clear();
}

void PhysicsEngine::Push(Collider const * collider, Rigidbody const * rigidbody)
{
    this->bodies.emplace_back(collider, rigidbody);
}
