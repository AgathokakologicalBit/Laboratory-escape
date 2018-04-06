#pragma once

#include "components/mesh.h"
#include "components/collider.h"
#include "components/rigidbody.h"


class PhysicsEngine
{
private:
    std::vector<std::pair<Collider const *, Rigidbody const *>> bodies;


public:
    void Update();

    void Push(Collider const * collider, Rigidbody const * rigidbody);


    friend class Engine;
};
