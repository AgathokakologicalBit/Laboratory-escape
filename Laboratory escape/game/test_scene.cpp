#include "../engine/scene.h"
#include "../engine/engine.h"
#include "test_scene.h"

void TestScene::Start()
{
	sf::Texture * texture = new sf::Texture();
	texture->loadFromFile("player.png");
	sprite = sf::Sprite(*texture);
	sprite.setScale(4, 4);
}

void TestScene::Update()
{
	Scene::Update();
	auto delta = Engine::Get().time.Delta();

	sprite.setPosition(sprite.getPosition() + sf::Vector2f(delta * 50, delta * 25));
	Engine::Get().window.draw(sprite);
}
