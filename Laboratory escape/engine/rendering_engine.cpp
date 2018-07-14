#include "rendering_engine.h"


void RenderingEngine::Push(RenderAction && action)
{
    actions.push(action);
}

void RenderingEngine::Update()
{
    window.clear();
    sf::Sprite sprite;

    while (!actions.empty())
    {
        auto const & act = actions.top();
        switch (act.type)
        {
        case RenderAction::Type::DrawSprite:
            if (!act.draw_data.texture) break;

            sprite.setTexture(*act.draw_data.texture, true);

            sprite.setColor(act.draw_data.tint);

            sprite.setPosition(act.position);
            sprite.setScale(act.scale);
            sprite.setRotation(act.rotation);

            window.draw(sprite);
            break;

        case RenderAction::Type::DrawShape:
            if (!act.draw_data.shape) break;

            auto& shape = *act.draw_data.shape;

            shape.setTexture(act.draw_data.texture.get());
            shape.setFillColor(act.draw_data.tint);

            shape.setPosition(act.position);
            shape.setScale(act.scale);
            shape.setRotation(act.rotation);
            
            window.draw(shape);
            break;
        }
        actions.pop();
    }

    window.display();
}
