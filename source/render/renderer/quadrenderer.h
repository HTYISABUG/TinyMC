#ifndef BASICRENDERER_H
#define BASICRENDERER_H

#include "math/glm.h"
#include "render/model.h"
#include "shader/basicshader.h"
#include "texture/basictexture.h"
#include <vector>

class Camera;

class QuadRenderer
{
public:
    QuadRenderer();

    void add(const Vector3 &pos);
    void render(const Camera &camera);

private:
    std::vector<Vector3> _positions;

    Model _model;
    BasicShader _shader;
    BasicTexture _texture;
};

#endif // BASICRENDERER_H
