#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "assets_manager.h"


class Material final
{
public:
	std::string name;

	sf::Color tint;
	sf::Texture const & texture;


public:
	Material() = default;
	Material(std::string texture_name)
		: name(texture_name)
		, tint(0xFFFFFFFF)
		, texture(AssetsManager::Get().LoadTexture(texture_name))
	{ }
	Material(std::string tilemap_name, std::string texture_name)
		: name(tilemap_name + '/' + texture_name)
		, tint(0xFFFFFFFF)
		, texture(AssetsManager::Get().LoadTile(tilemap_name, texture_name))
	{ }

	~Material() = default;
};
