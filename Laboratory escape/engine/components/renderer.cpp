#include "renderer.h"
#include "../engine.h"


void SpriteRenderer::Update()
{
    static auto & engine = Engine::Get().rendering_engine;
    if (!material.texture->getSize().x
        || !material.texture->getSize().y) return;
    engine.Push(RenderAction(layer, object->transform, material));
}

void ShapeRenderer::Update()
{
    static auto & engine = Engine::Get().rendering_engine;
    if (!shape) return;
    engine.Push(RenderAction(layer, object->transform, material, shape.get()));
}
