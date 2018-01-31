#include "physics_engine.h"
#include <exception>


void PhysicsEngine::Update()
{

}

void PhysicsEngine::PushMesh(sf::Vector2f position, sf::Vector2f size, Mesh const & mesh)
{
	throw new std::exception("not implemented");
}

void PhysicsEngine::PushCircle(sf::Vector2f position, float size)
{
	throw new std::exception("not implemented");
}
