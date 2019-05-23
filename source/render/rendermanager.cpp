#include "rendermanager.h"

RenderManager::RenderManager()
{
    _renderer.add(Vector3());
}

void RenderManager::render(const Camera &camera)
{
    glClearColor(.1f, .5, 1., 1.);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    _renderer.render(camera);
}
