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

	// scene_manager.Load([DefaultSceneGoesHere], SceneManager::StatePushMode::APPEND);

	return EXIT_SUCCESS;
}

bool Engine::Update()
{
	if (!window.isOpen() || scene_manager.Empty())
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

	scene_manager.Update();

	window.clear();
	window.display();

	return true;
}

void Engine::Stop()
{

}
