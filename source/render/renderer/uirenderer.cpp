#include "uirenderer.h"
#include "render/mesh.h"
#include "math/matrix.h"

void UiRenderer::add(const ColorMesh &mesh)
{
    _model.addData(mesh);
}

void UiRenderer::render()
{
    _shader.useProgram();
    _shader.loadProjectionMatrix(makeUiProjectionMatrix());

    _model.bindVAO();

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(_model.indicesCount()), GL_UNSIGNED_INT, nullptr);
}
