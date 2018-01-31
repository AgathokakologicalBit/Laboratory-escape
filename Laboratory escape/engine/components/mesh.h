#pragma once

#include "../component.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Mesh : public Component
{
public:
	std::vector<sf::Vector2f> points;
	std::vector<sf::Vector2i> edges;
	std::vector<sf::Vector3i> triangles;
};
