#include "collider.h"
#include "../engine.h"


void Collider::Update() const
{
	static PhysicsEngine & engine = Engine::Get().physics_engine;

	auto & transform = this->object->transform;
	switch (this->type)
	{
	case Type::Mesh: {
		auto & mesh = this->data.mesh;
		engine.PushMesh(transform.position, transform.scale * mesh.scale, *mesh.data);
	} break;
	case Type::Box: {
		static Mesh mesh(
			{ sf::Vector2f(-.5, -.5), sf::Vector2f(.5, -.5), sf::Vector2f(.5, .5), sf::Vector2f(-.5, .5) },
			{ sf::Vector2i(0, 1), sf::Vector2i(1, 2) , sf::Vector2i(2, 3) , sf::Vector2i(3, 0) , sf::Vector2i(1, 3) },
			{ sf::Vector3i(0, 1, 2), sf::Vector3i(0, 3, 2) }
		);

		engine.PushMesh(
			transform.position,
			sf::Vector2f
			(
				transform.scale.x * data.box.width,
				transform.scale.y * data.box.height
			),
			mesh
		);
	} break;
	case Type::Circle: {
		engine.PushCircle(transform.position, transform.scale.x * this->data.circle.radius);
	} break;
	}
}
