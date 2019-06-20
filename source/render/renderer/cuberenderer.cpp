#include "cuberenderer.h"
#include "constant.h"
#include "render/mesh.h"
#include "entity/camera.h"
#include "math/matrix.h"

CubeRenderer::CubeRenderer() :
    _atlas("texture_atlas.png")
{
    using namespace std;

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

    _model.addData(TextureMesh(CUBE_VERTEX_POSITION, textureCoords, CUBE_INDICES));
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
