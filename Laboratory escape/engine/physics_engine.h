#pragma once

#include "components/mesh.h"
#include "components/collider.h"
#include "components/rigidbody.h"


class PhysicsEngine
{
public:
    using body_info_t = std::pair<Collider const *, Rigidbody const *>;

private:
    std::vector<body_info_t> bodies;


public:
    void Update();

    void Push(Collider const * collider, Rigidbody const * rigidbody);


    friend class Engine;
};
