#pragma once

#include <SFML/Graphics.hpp>

class GameObject;

class Transform final
{
private:
	GameObject & game_object;

public:
	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;


public:
	Transform(GameObject &);
	~Transform() = default;
};
