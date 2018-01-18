#pragma once

#include <string>
#include "types.h"
#include "state.h"


class Scene : public State
{
private:
	SceneId id;
	std::string name;


public:
	Scene() = default;
	~Scene() = default;

	
public:
	void Start();
	void Pause();
	void Resume();
	void Stop();

	void Update();
};
