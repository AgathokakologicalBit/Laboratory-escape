#pragma once

#include <string>


class Component
{
private:
	bool is_initialized = false;

public:
	std::string name;


public:
	Component() = default;
	~Component() = default;

	friend class GameObject;
};

