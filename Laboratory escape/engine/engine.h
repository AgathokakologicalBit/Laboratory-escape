#pragma once

#include "time.h"


class Engine
{
private:
	sf::RenderWindow window;

	Time time;


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
