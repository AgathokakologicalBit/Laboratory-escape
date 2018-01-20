#include <SFML/Graphics.hpp>
#include "engine.h"

Engine::Engine()
	: time()
	, scene_manager()
	, rendering_engine("Laboratory escape")
{ }


int Engine::Start()
{
	time.clock.restart();
	return EXIT_SUCCESS;
}

bool Engine::Update()
{
	if (!rendering_engine.window.isOpen() || scene_manager.Empty())
		return false;

	sf::Event event;
	while (rendering_engine.window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			rendering_engine.window.close();
			return false;
		}
	}

	time.delta = time.clock.restart().asSeconds();

	scene_manager.Update();
	rendering_engine.Update();

	return true;
}

void Engine::Stop()
{

}
