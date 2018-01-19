#include "../engine/scene.h"
#include "../engine/engine.h"
#include "../engine/behavior.h"
#include "test_scene.h"


class PlayerComponent final : public Behavior
{
	sf::Sprite sprite;

	void Awake() final override
	{
		auto texture = new sf::Texture();
		texture->loadFromFile("player.png");

		sprite = sf::Sprite(*texture);
		sprite.setScale(4, 4);
	}

	void Start() final override { }
	void Finish() final override { }

	void Update() final override {
		auto delta = Engine::Get().time.Delta();
		object->transform.position.x += delta * 50;
		object->transform.position.y += delta * 25;

		sprite.setPosition(object->transform.position);

		Engine::Get().window.draw(sprite); // TODO: Move it to the renderer component
	}
};


void TestScene::Start()
{
	auto obj = new GameObject();
	obj->AddComponent(new PlayerComponent);

	objects.push_back(obj);
}

