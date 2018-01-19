#pragma once

#include <string>
#include "types.h"
#include "state.h"
#include "game_object.h"


class Scene : public State
{
private:
	SceneId id;
	std::string name;

	std::vector<GameObject *> objects;

public:
	Scene() = default;
	~Scene() = default;

	
public:
	virtual void Start() {};
	virtual void Pause() {};
	virtual void Resume() {};
	virtual void Stop() {};

	virtual void Update() {
		for (auto obj : objects)
		{
			if (!obj->is_initialized)
			{
				obj->Start();
				obj->is_initialized = true;
			}
			obj->Update();
		}
	};
};
