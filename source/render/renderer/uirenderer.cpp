#include "uirenderer.h"
#include "constant.h"
#include "render/mesh.h"
#include "math/matrix.h"
#include "ui/ui.h"
#include "world/block/blockmanager.h"
#include "entity/entity.h"

void UiRenderer::add(const Ui &ui)
{
    _uis.push_back(&ui);
}

void UiRenderer::render()
{

    for (auto ui : _uis) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);

        _uiShader.useProgram();
        _uiShader.loadProjectionMatrix(makeUiProjectionMatrix());

        ui->model2D().bindVAO();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(ui->model2D().indicesCount()), GL_UNSIGNED_INT, nullptr);


        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        _basicShader.useProgram();
        BlockManager::instance().textureAtlas().bindTexture();
        _basicShader.loadProjectionViewMatrix(makeUiProjectionMatrix());

        _basicShader.loadModelMatrix(makeModelMatrix({{0, 0, 0}, {0, 0, 0}}));

        ui->model3D().bindVAO();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(ui->model3D().indicesCount()), GL_UNSIGNED_INT, nullptr);
    }



    _uis.clear();
}
