#include "test_scene.h"
#include "../engine/engine.h"
#include "../engine/components/renderer.h"
#include "../engine/game_object.h"
#include "../engine/timer.h"


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
	Timer $timer_scene_start("scene start");

	auto player = SpawnObject<PlayerComponent, Renderer>();
	player->GetComponent<Renderer>()->material.SetTexture("player");

	for (int x = 1; x < 8; ++x)
	{
		for (int y = 0; y < 4; ++y)
		{
			auto p = 3 * (1 + (y == 0) - (y == 3)) + (1 - (x == 1) + (x == 7));

			auto stone = SpawnObject<Renderer>();
			stone->GetComponent<Renderer>()->material.SetTexture("dungeon_tileset", "ground_" + std::to_string(p));

			stone->transform.scale *= 2.f;
			stone->transform.position = sf::Vector2f(64 * x, 480 - 64 * (y + 1));
		}
	}
}
