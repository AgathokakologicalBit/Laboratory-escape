#pragma once

#include <queue>
#include "rendering_action.h"


class RenderingEngine
{
private:
    sf::RenderWindow window;
    std::priority_queue<RenderAction> actions;


public:
    RenderingEngine(std::string name)
        : window(sf::VideoMode(640, 480), name)
    {
        window.setFramerateLimit(30);
        window.setVerticalSyncEnabled(true);
    }

public:
    void Push(RenderAction && action);
    void Update();


    friend class Engine;
};
