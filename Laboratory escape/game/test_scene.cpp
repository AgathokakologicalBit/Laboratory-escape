#include "test_scene.h"
#include "../engine/engine.h"
#include "../engine/components/renderer.h"


class PlayerComponent final : public Behavior
{
	void Awake() final override
	{
		object->transform.scale = sf::Vector2f(4, 4);
	}

	void Start() final override { }
	void Finish() final override { }

	void Update() final override {
		object->transform.position += sf::Vector2f(50,  25) * Engine::Get().time.Delta();
	}
};


void TestScene::Start()
{
	auto obj = new GameObject();
	obj->AddComponent(new PlayerComponent);
	obj->AddComponent(new Renderer("player"));

	objects.push_back(obj);
}
