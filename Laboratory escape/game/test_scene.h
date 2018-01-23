#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/scene.h"
#include <memory>


class TestScene final : public Scene
{
private:
	sf::Sprite sprite;

public:
	void Start();
};
