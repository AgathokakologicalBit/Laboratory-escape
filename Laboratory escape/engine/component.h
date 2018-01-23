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
	std::string name;


public:
	Component() = default;
	~Component() = default;


public:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Finish() = 0;

	friend class GameObject;
};
