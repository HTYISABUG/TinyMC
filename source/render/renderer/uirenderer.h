#ifndef UIRENDERER_H
#define UIRENDERER_H

#include "shader/uishader.h"
#include "render/model/colormodel2d.h"
#include <vector>

struct ColorMesh;
class Camera;

class UiRenderer
{
public:
    void add(const ColorMesh &mesh);
    void render();

private:
    ColorModel2D _model;
    UiShader _shader;
};

#endif // UIRENDERER_H
