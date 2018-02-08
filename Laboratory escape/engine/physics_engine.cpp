#include "physics_engine.h"

#include <exception>


void PhysicsEngine::Update()
{

}

void PhysicsEngine::Push(Collider const * collider, Rigidbody const * rigidbody)
{
	this->bodies.emplace_back(collider, rigidbody);
}
