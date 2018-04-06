#pragma once

#include "../component.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Mesh: public Component
{
public:
    std::vector<sf::Vector2f> points;
    std::vector<sf::Vector2i> edges;
    std::vector<sf::Vector3i> triangles;


public:
    Mesh() = default;
    Mesh(std::vector<sf::Vector2f> points_, std::vector<sf::Vector2i> edges_, std::vector<sf::Vector3i> triangles_)
        : points(points_)
        , edges(edges_)
        , triangles(triangles_)
    { }
};
