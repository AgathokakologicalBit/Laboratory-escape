#include "rendering_engine.h"
#include <iostream>


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
		auto & act = actions.top();
		switch (act.type)
		{
		case RenderAction::Type::DrawTexture:
			sprite.setTexture(*act.draw_data.texture);
			sprite.setPosition(act.position);
			sprite.setScale(act.scale);

			// TODO: set right rotation
			window.draw(sprite);
			break;
		}
		actions.pop();
	}

	window.display();
}
