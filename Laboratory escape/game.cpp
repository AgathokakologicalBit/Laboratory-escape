#include <SFML/Graphics.hpp>
#include "engine/engine.h"


int main()
{
	auto error = Engine::Get().Start();
	if (error) return error;

	while (Engine::Get().Update()) ;
	Engine::Get().Stop();

	return EXIT_SUCCESS;
}
