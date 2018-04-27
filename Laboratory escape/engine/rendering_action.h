#pragma once

#include <SFML/Graphics.hpp>
#include "transform.h"
#include "material.h"


struct RenderAction final
{
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

    struct
    {
        sf::Texture const * texture;
        sf::Color tint;
    } draw_data;

public:
    RenderAction(int layer, Transform const & transform, Material const & material)
        : type(Type::DrawTexture)
        , layer(layer)
        , position(transform.position)
        , rotation(transform.rotation)
        , scale(transform.scale)
    {
        draw_data.texture = material.texture ? &*material.texture : nullptr;
        draw_data.tint = material.tint;
    }


    bool operator < (RenderAction const & r) const
    {
        return this->layer < r.layer;
    }

    friend class RenderingEngine;
};
