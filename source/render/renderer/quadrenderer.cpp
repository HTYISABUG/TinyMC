#include "basicrenderer.h"
#include "../mesh.h"
#include "../model.h"
#include "../../entity/camera.h"
#include "../../math/matrix.h"

BasicRenderer::BasicRenderer(const std::string &file) :
    _texture(file)
{
    _model.addData({
       {
           -0.5,  0.5, 0,
           0.5,  0.5, 0,
           0.5, -0.5, 0,
           -0.5, -0.5, 0,
       },
       {
           0, 1,
           1, 1,
           1, 0,
           0, 0,
       },
       {
           0, 1, 2,
           2, 3, 0
       }
   });
}

void BasicRenderer::add(const Vector3 &vec)
{
    _models.push_back(vec);
}

void BasicRenderer::render(const Camera &camera)
{
    if (_models.empty()) {
        return;
    }

    _shader.useProgram();
    _model.bindVAO();
    _texture.bindTexture();

    _shader.loadProjectionViewMatrix(camera.projectionViewMatrix());

    for (auto model : _models) {
        _shader.loadModelMatrix(makeModelMatrix({model, Vector3()}));
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_model.indicesCount()), GL_UNSIGNED_INT, nullptr);
    }

//    _models.clear();
}
