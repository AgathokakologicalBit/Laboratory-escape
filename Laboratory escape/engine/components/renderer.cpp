#include "renderer.h"
#include "../engine.h"


void Renderer::Awake()
{ }
void Renderer::Start()
{ }

void Renderer::Update()
{
    static auto & engine = Engine::Get().rendering_engine;
    if (!material.texture->getSize().x
        || !material.texture->getSize().y) return;
    engine.Push(RenderAction(layer, object->transform, material));
}

void Renderer::Finish()
{ }
