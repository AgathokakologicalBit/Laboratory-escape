#pragma once

#include "types.h"
#include "state_machine.h"
#include "scene.h"


class SceneManager final : public StateMachine<Scene>
{
public:
	SceneManager() = default;
	~SceneManager() = default;


public:
	template <typename SceneType>
	void Load(SceneType * scene, StatePushMode mode) { Push(scene, mode); }

	void Update() { StateMachine<Scene>::Update(); };
};
