#ifndef TYPES_H
#define TYPES_H

#include "vectorxz.h"
#include <iostream>
#include <glm/glm.hpp>

using Vector2 = glm::vec2;
using Vector3 = glm::vec3;
using Vector4 = glm::vec4;

using Vector2d = glm::dvec2;

using Vector2i = glm::ivec2;
using Vector3i = glm::ivec3;

using Matrix2 = glm::mat2;
using Matrix4 = glm::mat4;

template<class T>
std::ostream &operator <<(std::ostream &os, const glm::tvec3<T> &v)
{
    return os << '{' << v.x << ' ' << v.y << ' ' << v.z << '}';
}

#endif // TYPES_H
