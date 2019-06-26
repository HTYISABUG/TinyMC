#ifndef UI_H
#define UI_H

#include "render/model/colormodel2d.h"
#include "render/model/texturemodel3d.h"

struct GLFWwindow;

class Ui
{
public:
    virtual ~Ui() = default;

    virtual void handleEvent(GLFWwindow *window);

    const ColorModel2D &model2D() const;
    const TextureModel3D &model3D() const;

protected:
    virtual void makeMesh2D() = 0;

    ColorModel2D _model2D;
    TextureModel3D _model3D;
};

#endif // UI_H
