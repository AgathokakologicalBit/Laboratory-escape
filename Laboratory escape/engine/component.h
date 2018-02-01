#pragma once

#include <string>

class GameObject;

class Component
{
private:
	bool is_initialized = false;

protected:
	GameObject * object = nullptr;

public:
	bool is_active = true;


public:
	Component() = default;
	~Component() = default;


public:
	virtual void Awake() { };
	virtual void Start() { };
	virtual void Update() { };
	virtual void Finish() { };

	friend class GameObject;
};
