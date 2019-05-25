#include "rendermanager.h"

RenderManager::RenderManager()
{
//    addQuad(Vector3());
    addCube(Vector3());
}

void RenderManager::render(const Camera &camera)
{
    glClearColor(.1f, .5, 1., 1.);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    _quadRenderer.render(camera);
    _cubeRenderer.render(camera);
}

void RenderManager::addQuad(const Vector3 &pos)
{
    _quadRenderer.add(pos);
}

void RenderManager::addCube(const Vector3 &pos)
{
    _cubeRenderer.add(pos);
}
