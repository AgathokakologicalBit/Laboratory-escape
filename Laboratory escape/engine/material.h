#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <string_view>
#include "assets_manager.h"


class Material final
{
public:
	std::string name;

	sf::Color tint;
	std::shared_ptr<sf::Texture const> texture;


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


public:
	void SetTexture(std::string_view name_)
	{
		texture = AssetsManager::Get().LoadTexture(name_);
	}

	void SetTexture(std::string_view map_name, std::string_view name_)
	{
		texture = AssetsManager::Get().LoadTile(map_name, name_);
	}
};
