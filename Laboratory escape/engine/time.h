#pragma once

#include <SFML/Graphics.hpp>

class Time
{
private:
	sf::Clock clock;
	float delta;

public:
	inline float Delta() const { return delta; }
	inline float Fps() const { return 1.f / delta; }

	friend class Engine;
};
