#pragma once

#include <SFML/Graphics.hpp>
#include "../behavior.h"


class Rigidbody final: public Behavior
{
public:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;


public:
    void AddForce(float direction, float force);
};
