#ifndef ENTITY_H
#define ENTITY_H

#include "../math/glm.h"

struct Entity
{
public:
    Entity(const Vector3 &position = Vector3(), const Vector3 &rotation = Vector3());

    Vector3 position() const;
    Vector3 rotation() const;

protected:
    Vector3 _position;
    Vector3 _rotation;
};

#endif // ENTITY_H
