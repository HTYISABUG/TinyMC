#include "entity.h"

Entity::Entity(const Vector3 &position, const Vector3 &rotation) :
    _position(position),
    _rotation(rotation)
{

}

Vector3 Entity::position() const
{
    return _position;
}

Vector3 Entity::rotation() const
{
    return _rotation;
}
