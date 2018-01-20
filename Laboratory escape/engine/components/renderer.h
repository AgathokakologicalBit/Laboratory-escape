#pragma once

#include "../behavior.h"
#include "../material.h"
#include "../types.h"

class Renderer final : public Behavior
{
public:
	Layer layer;
	Material material;


public:
	Renderer(std::string texture_name)
		: layer(0)
		, material(texture_name)
	{ }

public:
	void Awake() final override;
	void Start() final override;
	void Update() final override;
	void Finish() final override;
};
