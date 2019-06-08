#include "matrix.h"
#include "glm.h"
#include "entity/entity.h"
#include "entity/camera.h"

#define WIDTH 800.f
#define HEIGHT 600.f

using namespace glm;

Matrix4 makeModelMatrix(const Entity &entity)
{
    Matrix4 matrix(1);

    matrix = rotate(matrix, radians(entity.rotation.x), {1, 0, 0});
    matrix = rotate(matrix, radians(entity.rotation.y), {0, 1, 0});
    matrix = rotate(matrix, radians(entity.rotation.z), {0, 0, 1});
    matrix = translate(matrix, entity.position);

    return matrix;
}

Matrix4 makeViewMatrix(const Camera &camera)
{
    auto d = sight(camera);
    auto u = up(camera);

    const auto &position = camera.position;

    return lookAt(position, position + d, u);
}

Matrix4 makeProjectionMatrix(float fov)
{
    return perspective(radians(fov), WIDTH / HEIGHT, 0.1f, 1000.f);
}

Vector3 sight(const Camera &camera)
{
    const auto &rotation = camera.rotation;

    return {
        cos(rotation.x) * -sin(rotation.y),
        sin(rotation.x),
        cos(rotation.x) * -cos(rotation.y),
    };
}

Vector3 right(const Camera &camera)
{
    static const auto deg90 = radians(90.f);

    const auto &rotation = camera.rotation;

    return {
        -sin(rotation.y - deg90),
        0,
        -cos(rotation.y - deg90),
    };
}

Vector3 up(const Camera &camera)
{
    const auto &rotation = camera.rotation;
    const auto d = sight(camera);
    const auto r = right(camera);

    return angleAxis(-rotation.z, d) * cross(r, d);
}
