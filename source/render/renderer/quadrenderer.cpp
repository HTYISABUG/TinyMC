#include "quadrenderer.h"
#include "render/mesh.h"
#include "entity/camera.h"
#include "math/matrix.h"

QuadRenderer::QuadRenderer() :
    _texture("blocks/grass_side.png")
{
    using namespace std;

    static const vector<GLfloat> vertexPosition = {
        -0.5,  0.5, 0,
        -0.5, -0.5, 0,
         0.5, -0.5, 0,
         0.5,  0.5, 0,
    };

    static const vector<GLfloat> textureCoords = {
        0, 1,
        0, 0,
        1, 0,
        1, 1,
    };

    static const vector<GLuint> indices = {
        0, 1, 2,
        2, 3, 0
    };

    _model.addData({vertexPosition, textureCoords, indices});
}

void QuadRenderer::add(const Vector3 &pos)
{
    _positions.push_back(pos);
}

void QuadRenderer::render(const Camera &camera)
{
    if (_positions.empty()) {
        return;
    }

    _shader.useProgram();
    _model.bindVAO();
    _texture.bindTexture();

    _shader.loadProjectionViewMatrix(camera.projectionViewMatrix());

    for (auto pos : _positions) {
        _shader.loadModelMatrix(makeModelMatrix({pos, Vector3()}));
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_model.indicesCount()), GL_UNSIGNED_INT, nullptr);
    }

//    _positions.clear();
}
