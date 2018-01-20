#pragma once

#include <SFML/Graphics.hpp>
#include "transform.h"


struct RenderAction final {
public:
	enum class Type
	{
		DrawTexture
	};

private:
	Type type;

	int layer;

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;

	union
	{
		sf::Texture const * texture;
	} draw_data;

public:
	RenderAction(int layer, Transform const & transform, sf::Texture const * const texture)
		: type(Type::DrawTexture)
		, layer(layer)
		, position(transform.position)
		, rotation(transform.rotation)
		, scale(transform.scale)
	{
		draw_data.texture = texture;
	}


	bool operator < (RenderAction const & r) const
	{
		return this->layer < r.layer;
	}

	friend class RenderingEngine;
};
