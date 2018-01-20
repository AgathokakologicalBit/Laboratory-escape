#pragma once

#include "../behavior.h"
#include "../material.h"

class Renderer final : public Behavior
{
public:
	Material material;

public:
	void Awake() final override;
	void Start() final override;
	void Update() final override;
	void Finish() final override;
};
