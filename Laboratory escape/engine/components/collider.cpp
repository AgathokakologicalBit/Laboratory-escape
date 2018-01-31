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
	case Type::Circle: {
		engine.PushCircle(transform.position, transform.scale.x * this->data.circle.radius);
	} break;
	}
}
