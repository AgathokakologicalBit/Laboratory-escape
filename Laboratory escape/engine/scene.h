#pragma once

#include <string>
#include "types.h"

class Scene
{
private:
	SceneId id;
	std::string name;


public:
	Scene() = default;
	~Scene() = default;

	
protected:
	virtual void Load() = 0;
	virtual void Unload() = 0;


	friend class SceneManager;
};
