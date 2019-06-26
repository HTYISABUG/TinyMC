#ifndef UIRENDERER_H
#define UIRENDERER_H

#include "shader/uishader.h"
#include "shader/basicshader.h"
#include "render/model/colormodel2d.h"
#include <vector>

class Ui;
class Camera;

class UiRenderer
{
public:
    friend class RenderManager;

    void add(const Ui &ui);
    void render();

private:
    UiRenderer() = default;

    std::vector<const Ui *> _uis;

    UiShader _uiShader;
    BasicShader _basicShader;
};

#endif // UIRENDERER_H
