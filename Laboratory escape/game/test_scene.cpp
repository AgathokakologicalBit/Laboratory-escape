#include "test_scene.h"


class PlayerComponent final: public Behavior
{
    void Awake() final override
    {
        object->transform.scale = sf::Vector2f(4, 4);
    }

    void Update() final override
    {
        object->transform.position += sf::Vector2f(50, 25) * Engine::Get().time.Delta();
    }
};


void TestScene::Start()
{
    auto player = SpawnObject<PlayerComponent, Collider, SpriteRenderer>();
    player->GetComponent<SpriteRenderer>()->material.SetTexture("player");

    for (int x = 1; x < 8; ++x)
    {
        for (int y = 0; y < 4; ++y)
        {
            auto p = 3 * (1 + (y == 0) - (y == 3)) + (1 - (x == 1) + (x == 7));

            auto stone = SpawnObject<Collider, SpriteRenderer>();
            stone->GetComponent<SpriteRenderer>()->material.SetTexture("dungeon_tileset", "ground_" + std::to_string(p));

            stone->transform.scale *= 2.f;
            stone->transform.position = sf::Vector2f(64.f * x, 480.f - 64 * (y + 1));
        }
    }
}
