#include "matrix.h"
#include "../entity/entity.h"
#include "../entity/camera.h"

#define WIDTH 800.f
#define HEIGHT 600.f

using namespace glm;

Matrix4 makeModelMatrix(const Entity &entity)
{
    Matrix4 matrix(1);

    matrix = rotate(matrix, radians(entity.rotation().x), {1, 0, 0});
    matrix = rotate(matrix, radians(entity.rotation().y), {0, 1, 0});
    matrix = rotate(matrix, radians(entity.rotation().z), {0, 0, 1});
    matrix = translate(matrix, entity.position());

    return matrix;
}

Matrix4 makeViewMatrix(const Camera &camera)
{
    Matrix4 matrix(1);

    matrix = rotate(matrix, radians(camera.rotation().x), {1, 0, 0});
    matrix = rotate(matrix, radians(camera.rotation().y), {0, 1, 0});
    matrix = rotate(matrix, radians(camera.rotation().z), {0, 0, 1});
    matrix = translate(matrix, -camera.position());

    return matrix;
}

Matrix4 makeProjectionMatrix(float fov)
{
    return perspective(radians(fov), WIDTH / HEIGHT, 0.1f, 1000.f);
}
