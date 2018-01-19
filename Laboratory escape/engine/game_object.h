#pragma once

#include <vector>

#include "component.h"
#include "types.h"
#include "transform.h"


class GameObject final
{
private:
	using ComponentArrayType = std::vector<Component *>;

private:
	ComponentArrayType _components;
	bool is_initialized = false;

public:
	std::string name;
	Layer layer;

	Transform transform;


public:
	GameObject();
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

	friend class Scene;
};
