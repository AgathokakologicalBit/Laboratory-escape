#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include <string_view>
#include <map>
#include <memory>
#include <fstream>

#ifdef DEBUG_
#include <iostream>
#endif

class AssetsManager final
{
private:
    std::map<std::string, std::shared_ptr<sf::Image const>> images;
    std::map<std::string, std::shared_ptr<sf::Texture const>> textures;

public:
    static AssetsManager & Get()
    {
        static AssetsManager instance;
        return instance;
    }


private:
    std::shared_ptr<sf::Image const> LoadImage(std::string_view name)
    {
        std::string name_str(name);

        if (images.count(name_str))
            return images.at(name_str);

#ifdef DEBUG_
        std::cout << "Load image '" << name << "' from drive\n";
#endif
        auto image = std::make_shared<sf::Image>();

        image->loadFromFile("assets/" + name_str + ".png");
        images.emplace(name, image);

        return image;
    }

public:
    std::shared_ptr<sf::Texture const> LoadTexture(std::string_view name)
    {
        std::string name_str(name);
        std::transform(name_str.begin(), name_str.end(), name_str.begin(), ::tolower);

        if (textures.count(name_str))
            return textures.at(name_str);

        auto image = LoadImage(name_str);
        auto texture = std::make_shared<sf::Texture>();

        texture->loadFromImage(*image);
        textures.emplace(name_str, texture);

        return texture;
    }

    std::shared_ptr<sf::Texture const> LoadTile(std::string_view map_name, std::string_view name)
    {
        std::string map_name_str(map_name);
        std::string name_str(name);

        std::transform(map_name_str.begin(), map_name_str.end(), map_name_str.begin(), ::tolower);
        std::transform(name_str.begin(), name_str.end(), name_str.begin(), ::tolower);



        auto full_name = map_name_str + '/' + name_str;
        if (textures.count(full_name))
            return textures.at(full_name);

        auto image = LoadImage(map_name);
        std::ifstream data("assets/" + map_name_str + ".dat", std::ifstream::in);

        std::size_t count;
        data >> count;
        for (std::size_t i = 0; i < count; ++i)
        {
            auto texture = std::make_shared<sf::Texture>();
            sf::Vector2i offset, size;
            std::string tile_name;
            data >> tile_name >> offset.y >> offset.x >> size.y >> size.x;

#ifdef DEBUG_
            std::cout
                << "  Load sub-tile '" << name
                << "' with offset (" << offset.y << ", " << offset.x << ')'
                << ", size (" << size.y << ", " << size.x << ")\n";
#endif
            texture->loadFromImage(*image, sf::IntRect(offset, size));
            textures.emplace(map_name_str + '/' + tile_name, texture);
        }

        return textures.at(full_name);
    }
};
