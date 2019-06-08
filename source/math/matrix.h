#ifndef MATRIX_H
#define MATRIX_H

#include "types.h"

class Entity;
class Camera;

Matrix4 makeModelMatrix(const Entity &entity);
Matrix4 makeViewMatrix(const Camera &camera);
Matrix4 makeProjectionMatrix(float fov);

#endif // MATRIX_H
