#ifndef BASICRENDERER_H
#define BASICRENDERER_H

#include "../model.h"
#include "../../shader/basicshader.h"
#include "../../texture/basictexture.h"
#include <vector>

class Camera;

class BasicRenderer
{
public:
    BasicRenderer(const std::string &file = "cobblestone.png");

    void add(const Vector3 &vec);
    void render(const Camera &camera);
    void _render(const Camera &camera);

private:
    std::vector<Vector3> _models;

    Model _model;
    BasicShader _shader;
    BasicTexture _texture;
};

#endif // BASICRENDERER_H
