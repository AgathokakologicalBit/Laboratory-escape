#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include <map>


class AssetsManager final
{
private:
	std::map<std::string, sf::Texture const *> textures;

public:
	static AssetsManager & Get()
	{
		static AssetsManager instance;
		return instance;
	}


public:
	sf::Texture const & LoadTexture(std::string name)
	{
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		if (textures.count(name)) return *textures.at(name);

		auto texture = new sf::Texture;
		textures.emplace(name, texture);
		texture->loadFromFile(name + ".png");
		return *texture;
	}
};
