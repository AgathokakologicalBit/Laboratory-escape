#pragma once

#include <string>
#include <string_view>
#include "../behavior.h"
#include "../material.h"
#include "../util/types.h"

class Renderer: public Behavior
{
public:
    Layer layer;
    Material material;


public:
    Renderer()
        : layer(0)
        , material()
    { };


public:
    virtual void Awake() override
    { };
    virtual void Start() override
    { };
    virtual void Update() override = 0;
    virtual void Finish() override
    { };
};


class SpriteRenderer: public Renderer
{
public:
    virtual void Update() override;
};

class ShapeRenderer: public Renderer
{
private:
    std::unique_ptr<sf::Shape> shape;


public:
    inline void SetShape(sf::Shape * shape)
    {
        this->shape.reset(shape);
    }

public:
    virtual void Update() override;
};
