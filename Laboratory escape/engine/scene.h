#pragma once

#include <cassert>
#include <string>
#include "types.h"
#include "state.h"
#include "game_object.h"


class Scene : public State
{
public:
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


public:
	template <typename... Ct>
	GameObject * SpawnObject(Ct * ... components)
	{
		auto obj = new GameObject;
		
		bool res = ((obj->AddComponent(components)) & ...);
		assert(res);

		objects.push_back(obj);
		return obj;
	}

};
