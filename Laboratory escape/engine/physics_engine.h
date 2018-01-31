#pragma once

#include "components/mesh.h"


class PhysicsEngine
{
private:
	struct Collider { };

private:
	std::vector<Collider> colliders;


public:
	void Update();

	void PushMesh(sf::Vector2f position, sf::Vector2f size, Mesh const & mesh);
	void PushCircle(sf::Vector2f position, float size);


	friend class Engine;
};
