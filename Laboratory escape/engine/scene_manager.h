#pragma once

#include "types.h";

class SceneManager final
{
public:
	SceneManager() = default;
	~SceneManager() = default;


public:
	void Load(SceneId id);
};
