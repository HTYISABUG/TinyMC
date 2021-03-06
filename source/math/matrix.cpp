#include "matrix.h"
#include "constant.h"
#include "glm.h"
#include "entity/entity.h"
#include "entity/camera.h"

#define WIDTH static_cast<float>(WINDOW_WIDTH)
#define HEIGHT static_cast<float>(WINDOW_HEIGHT)

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
    auto &position = camera.position;
    auto d = camera.front();
    auto u = camera.up();

    return lookAt(position, position + d, u);
}

Matrix4 makeProjectionMatrix(float fov)
{
    return perspective(radians(fov), WIDTH / HEIGHT, 0.1f, 1000.f);
}

Matrix4 makeUiProjectionMatrix()
{
    static auto m = ortho(0.f, WIDTH, 0.f, HEIGHT);
    return m;
}
