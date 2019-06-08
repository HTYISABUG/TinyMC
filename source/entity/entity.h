#ifndef ENTITY_H
#define ENTITY_H

#include "math/types.h"

struct Entity
{
    Vector3 front() const;
    Vector3 right() const;
    Vector3 up() const;

    Vector3 position;
    Vector3 rotation;
};

#endif // ENTITY_H
