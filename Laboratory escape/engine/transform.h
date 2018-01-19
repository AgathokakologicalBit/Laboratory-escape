#pragma once

#include <SFML/Graphics.hpp>

class GameObject;

class Transform final
{
private:
	GameObject & game_object;

public:
	sf::Vector2f position;
	sf::Vector2f rotation;
	sf::Vector2f scale;


public:
	Transform(GameObject &);
	~Transform() = default;
};
