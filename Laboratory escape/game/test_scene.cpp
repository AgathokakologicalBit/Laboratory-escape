#include "../engine/scene.h"
#include "../engine/engine.h"
#include "../engine/behavior.h"
#include "test_scene.h"


class PlayerComponent final : public Behavior
{
	sf::Texture texture;

	void Awake() final override
	{
		texture = sf::Texture();
		texture.loadFromFile("player.png");
		object->transform.scale = sf::Vector2f(4, 4);
	}

	void Start() final override { }
	void Finish() final override { }

	void Update() final override {
		auto delta = Engine::Get().time.Delta();
		object->transform.position += sf::Vector2f(delta * 50, delta * 25);

		Engine::Get().rendering_engine.Push(RenderAction(0, object->transform, &texture));
	}
};


void TestScene::Start()
{
	auto obj = new GameObject();
	obj->AddComponent(new PlayerComponent);

	objects.push_back(obj);
}
