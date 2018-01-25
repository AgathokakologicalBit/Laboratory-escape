#pragma once

#include <SFML/Graphics.hpp>
#include "../behavior.h"


class Collider final : public virtual Behavior
{
public:
	enum class Type {
		Mesh,
		Box,
		Circle,
	};

	Type type;

	sf::Vector2f offset{ .0f, .0f };
	sf::Vector2f pivot{ .5f, .5f };

	union
	{
		union
		{
			float width;
			float height;
		} box;

		union
		{
			float radius;
		} circle;
	} data{ 0.0 };

public:
	void Update() const;
};
