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

	
protected:
	void Start();
	void Pause();
	void Resume();
	void Stop();

	void Update();


	friend class SceneManager;
};
