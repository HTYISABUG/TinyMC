#ifndef CUDERENDERER_H
#define CUDERENDERER_H

#include "math/glm.h"
#include "render/model/texturemodel3d.h"
#include "shader/basicshader.h"
#include "texture/textureatlas.h"
#include <vector>

class Camera;

class CubeRenderer
{
public:
    CubeRenderer();

    void add(const Vector3 &pos);
    void render(const Camera &camera);

private:
    std::vector<Vector3> _positions;

    TextureModel3D _model;
    BasicShader _shader;
    TextureAtlas _atlas;
};

#endif // CUDERENDERER_H
