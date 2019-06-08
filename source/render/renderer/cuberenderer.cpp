#include "cuberenderer.h"
#include "render/mesh.h"
#include "entity/camera.h"
#include "math/matrix.h"

CubeRenderer::CubeRenderer() :
    _atlas("texture_atlas.png")
{
    using namespace std;

    static const vector<GLfloat> vertexPosition = {
        // front
        -0.5,  0.5,  0.5,
        -0.5, -0.5,  0.5,
         0.5, -0.5,  0.5,
         0.5,  0.5,  0.5,

        // back
         0.5,  0.5, -0.5,
         0.5, -0.5, -0.5,
        -0.5, -0.5, -0.5,
        -0.5,  0.5, -0.5,

        // right
         0.5,  0.5,  0.5,
         0.5, -0.5,  0.5,
         0.5, -0.5, -0.5,
         0.5,  0.5, -0.5,

        // left
        -0.5,  0.5, -0.5,
        -0.5, -0.5, -0.5,
        -0.5, -0.5,  0.5,
        -0.5,  0.5,  0.5,

        // top
        -0.5,  0.5, -0.5,
        -0.5,  0.5,  0.5,
         0.5,  0.5,  0.5,
         0.5,  0.5, -0.5,

        // bottom
        -0.5, -0.5,  0.5,
        -0.5, -0.5, -0.5,
         0.5, -0.5, -0.5,
         0.5, -0.5,  0.5,
    };

    auto top    = _atlas.getTexture({2,  0});
    auto side   = _atlas.getTexture({3,  0});
    auto bottom = _atlas.getTexture({11, 1});

    vector<GLfloat> textureCoords;
    textureCoords.insert(textureCoords.end(), side.begin(),   side.end());
    textureCoords.insert(textureCoords.end(), side.begin(),   side.end());
    textureCoords.insert(textureCoords.end(), side.begin(),   side.end());
    textureCoords.insert(textureCoords.end(), side.begin(),   side.end());
    textureCoords.insert(textureCoords.end(), top.begin(),    top.end());
    textureCoords.insert(textureCoords.end(), bottom.begin(), bottom.end());

    static const vector<GLuint> indices = {
        // front
        0, 1, 2,
        2, 3, 0,

        // back
        4, 5, 6,
        6, 7, 4,

        // right
        8, 9, 10,
        10, 11, 8,

        // left
        12, 13, 14,
        14, 15, 12,

        // top
        16, 17, 18,
        18, 19, 16,

        // bottom
        20, 21, 22,
        22, 23, 20,
    };

    _model.addData({vertexPosition, textureCoords, indices});
}

void CubeRenderer::add(const Vector3 &pos)
{
    _positions.push_back(pos);
}

void CubeRenderer::render(const Camera &camera)
{
    _shader.useProgram();
    _model.bindVAO();
    _atlas.bindTexture();

    _shader.loadProjectionViewMatrix(camera.projectionViewMatrix());

    for (const auto &pos : _positions) {
        _shader.loadModelMatrix(makeModelMatrix({pos, Vector3()}));
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_model.indicesCount()), GL_UNSIGNED_INT, nullptr);
    }

    _positions.clear();
}
