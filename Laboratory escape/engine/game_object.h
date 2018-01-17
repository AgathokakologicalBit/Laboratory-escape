#pragma once

#include <vector>
#include "component.h"
#include "types.h"


class GameObject final
{
private:
	using ComponentArrayType = std::vector<Component>();

private:
	ComponentArrayType _components;

public:
	std::string name;
	Layer layer;


public:
	GameObject() = default;
	~GameObject() = default;


protected:
	void Awake();
	void Start();
	void Update();
	void Finish();

public:
	template <typename ComponentType>
	ComponentType * GetComponent() const;
	Component * GetComponent(std::string name) const;

	template <typename ComponentType>
	void AddComponent();
};
