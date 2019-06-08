#include "entity.h"
#include "math/glm.h"

using namespace glm;

Vector3 Entity::front() const
{
    return {
        cos(rotation.x) * -sin(rotation.y),
        sin(rotation.x),
        cos(rotation.x) * -cos(rotation.y),
    };
}

Vector3 Entity::right() const
{
    static const auto deg90 = radians(90.f);

    return {
        -sin(rotation.y - deg90),
        0,
        -cos(rotation.y - deg90),
    };
}

Vector3 Entity::up() const
{
    const auto d = front();
    const auto r = right();

    return angleAxis(-rotation.z, d) * cross(r, d);
}
