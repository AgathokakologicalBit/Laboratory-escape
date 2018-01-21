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
	auto player = new GameObject;
	player->AddComponent(new PlayerComponent);
	player->AddComponent(new Renderer("player"));
	objects.push_back(player);

	for (int x = 1; x < 8; ++x)
	{
		for (int y = 0; y < 4; ++y)
		{
			auto stone = new GameObject;
			stone->AddComponent(new Renderer("dungeon_tileset",
				y == 3 ? x == 7 ? "ground_top_right" : "ground_top" : x == 7 ? "ground_right" : "ground_center"));
			stone->transform.scale *= 2.f;
			stone->transform.position = sf::Vector2f(32 * 2 * x, 480 - 32 * 2 * (y + 1));
			objects.push_back(stone);
		}
	}
}
