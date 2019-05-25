#include "matrix.h"
#include "../entity/entity.h"
#include "../entity/camera.h"

#define WIDTH 800.f
#define HEIGHT 600.f

using namespace glm;

Matrix4 makeModelMatrix(const Entity &entity)
{
    Matrix4 matrix(1);

    matrix = rotate(matrix, radians(entity._rotation.x), {1, 0, 0});
    matrix = rotate(matrix, radians(entity._rotation.y), {0, 1, 0});
    matrix = rotate(matrix, radians(entity._rotation.z), {0, 0, 1});
    matrix = translate(matrix, entity._position);

    return matrix;
}

Matrix4 makeViewMatrix(const Camera &camera)
{
    auto rotation = camera.rotation();

    Vector3 direction = {
        -cos(rotation.x) * sin(rotation.y),
        -sin(rotation.x),
        -cos(rotation.x) * cos(rotation.y),
    };

    static const auto deg90 = radians(90.f);

    Vector3 right = {
        -sin(rotation.y - deg90),
        -0,
        -cos(rotation.y - deg90),
    };


    auto up = angleAxis(rotation.z, direction) * cross(right, direction);
    auto position = camera.position();

    return lookAt(position, position + direction, up);
}

Matrix4 makeProjectionMatrix(float fov)
{
    return perspective(radians(fov), WIDTH / HEIGHT, 0.1f, 1000.f);
}
