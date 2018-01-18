#include <SFML/Graphics.hpp>
#include "engine/engine.h"

#include "game/test_scene.h"

int main()
{
	auto error = Engine::Get().Start();
	if (error) return error;

	Engine::Get().scene_manager.Load(new TestScene, SceneManager::StatePushMode::APPEND);

	while (Engine::Get().Update()) ;
	Engine::Get().Stop();

	return EXIT_SUCCESS;
}
