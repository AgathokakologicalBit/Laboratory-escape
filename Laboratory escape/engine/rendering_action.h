#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

#include "transform.h"
#include "material.h"


struct RenderAction final
{
public:
    enum class Type
    {
        DrawSprite,
        DrawShape,
        DrawText,
    };

private:
    Type type;

    int layer;

    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

    struct draw_data_t
    {
        std::shared_ptr<sf::Texture const> texture;
        sf::Color tint;

        union
        {
            sf::Shape * shape;
        };
    } draw_data;

public:
    RenderAction(int layer, Transform const & transform, Material const & material)
        : type(Type::DrawSprite)
        , layer(layer)
        , position(transform.position)
        , rotation(transform.rotation)
        , scale(transform.scale)
        , draw_data { material.texture, material.tint }
    { }

    RenderAction(int layer, Transform const & transform, Material const & material, sf::Shape * shape)
        : type(Type::DrawShape)
        , layer(layer)
        , position(transform.position)
        , rotation(transform.rotation)
        , scale(transform.scale)
        , draw_data { material.texture, material.tint, shape }
    { }


    bool operator < (RenderAction const & r) const
    {
        return this->layer < r.layer;
    }

    friend class RenderingEngine;
};
