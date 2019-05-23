#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "renderer/basicrenderer.h"

class Camera;

class RenderManager
{
public:
    RenderManager();

    void render(const Camera &camera);

private:
    BasicRenderer _renderer;
};

#endif // RENDERMANAGER_H
