#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <fstream>


class AssetsManager final
{
private:
	std::map<std::string, sf::Image const *> images;
	std::map<std::string, sf::Texture const *> textures;

public:
	static AssetsManager & Get()
	{
		static AssetsManager instance;
		return instance;
	}


private:
	sf::Image const & LoadImage(std::string name)
	{
		if (images.count(name))
			return *images.at(name);
		
		std::cout << "Load image '" << name << "' from drive\n";

		auto image = new sf::Image;

		image->loadFromFile("assets/" + name + ".png");
		images.emplace(name, image);

		return *image;
	}

public:
	sf::Texture const & LoadTexture(std::string name)
	{
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		
		if (textures.count(name))
			return *textures.at(name);

		auto image = LoadImage(name);
		auto texture = new sf::Texture;

		texture->loadFromImage(image);
		textures.emplace(name, texture);
		
		return *texture;
	}

	sf::Texture const & LoadTile(std::string map_name, std::string name)
	{
		std::transform(map_name.begin(), map_name.end(), map_name.begin(), ::tolower);
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);

		auto full_name = map_name + '/' + name;
		if (textures.count(full_name))
			return *textures.at(full_name);

		auto image = LoadImage(map_name);
		std::ifstream data("assets/" + map_name + ".dat", std::ifstream::in);

		std::size_t count;
		data >> count;
		for (std::size_t i = 0; i < count; ++i)
		{
			auto texture = new sf::Texture;
			sf::Vector2i offset, size;
			std::string name;
			data >> name >> offset.y >> offset.x >> size.y >> size.x;

			std::cout
				<< "  Load sub-tile '" << name
				<< "' with offset (" << offset.y << ", " << offset.x << ')'
				<< ", size (" << size.y << ", " << size.x << ")\n";
			
			texture->loadFromImage(image, sf::IntRect(offset, size));
			textures.emplace(map_name + '/' + name, texture);
		}

		return *textures.at(full_name);
	}
};
