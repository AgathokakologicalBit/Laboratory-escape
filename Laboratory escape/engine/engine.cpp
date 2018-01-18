#include <SFML/Graphics.hpp>
#include "engine.h"


Engine::Engine()
	: window(sf::VideoMode(640, 480), "Laboratory escape")
{
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);
}


int Engine::Start()
{
	time.clock.restart();
	return EXIT_SUCCESS;
}

bool Engine::Update()
{
	if (!window.isOpen())
		return false;

	time.delta = time.clock.restart().asSeconds();

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			return false;
		}
	}

	window.clear();
	window.display();

	return true;
}

void Engine::Stop()
{

}
