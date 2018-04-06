#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

#include "../engine/engine.h"
#include "../engine/scene.h"
#include "../engine/components/renderer.h"


class TestScene final: public Scene
{
public:
    void Start();
};
