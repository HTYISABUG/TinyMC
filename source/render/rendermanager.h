#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "renderer/quadrenderer.h"
#include "renderer/cuberenderer.h"

class Camera;

class RenderManager
{
public:
    RenderManager();

    void render(const Camera &camera);

private:
    void addQuad(const Vector3 &pos);
    void addCube(const Vector3 &pos);

    QuadRenderer _quadRenderer;
    CubeRenderer _cubeRenderer;
};

#endif // RENDERMANAGER_H
