#include "uirenderer.h"
#include "render/mesh.h"
#include "math/matrix.h"
#include "ui/ui.h"

void UiRenderer::add(const Ui &ui)
{
    _uis.push_back(&ui);
}

void UiRenderer::render()
{
    _shader.useProgram();
    _shader.loadProjectionMatrix(makeUiProjectionMatrix());

    for (auto ui : _uis) {
        ui->model().bindVAO();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(ui->model().indicesCount()), GL_UNSIGNED_INT, nullptr);
    }

    _uis.clear();
}
