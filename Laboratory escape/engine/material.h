#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Material final
{
private:
	std::string name;

	sf::Color tint;
	sf::Texture texture;


public:
	Material() = default;
	~Material() = default;
};
