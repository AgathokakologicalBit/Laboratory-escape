#pragma once

#include "time.h"
#include "scene_manager.h"


class Engine
{
private:
	sf::RenderWindow window;

	Time time;
	SceneManager scene_manager;


public:
	Engine();
	~Engine() = default;

	static Engine & Get()
	{
		static auto instance = new Engine;
		return *instance;
	}
	

public:
	int Start();
	bool Update();
	void Stop();
};
