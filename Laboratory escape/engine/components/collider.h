#pragma once

#include <SFML/Graphics.hpp>
#include "../behavior.h"
#include "mesh.h"


class Collider final : public Behavior
{
public:
	bool is_static = false;

	enum class Type {
		Mesh,
		Box,
		Circle,
	};

	Type type{ Type::Mesh };

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

		union
		{
			float scale;
			Mesh * data;
		} mesh;
	} data{ 0.0 };

public:
	void Update() const;
};
