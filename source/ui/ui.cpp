#include "ui.h"
#include "render/mesh.h"

void Ui::handleEvent(GLFWwindow *window)
{

}

const ColorModel2D &Ui::model2D() const
{
    return _model2D;
}

const TextureModel3D &Ui::model3D() const
{
    return _model3D;
}
