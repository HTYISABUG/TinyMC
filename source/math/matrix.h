#ifndef MATRIX_H
#define MATRIX_H

#include "types.h"

class Entity;
class Camera;

Matrix4 makeModelMatrix(const Entity &entity);
Matrix4 makeViewMatrix(const Camera &camera);
Matrix4 makeProjectionMatrix(float fov);

Vector3 sight(const Camera &camera);
Vector3 right(const Camera &camera);
Vector3 up(const Camera &camera);

#endif // MATRIX_H
