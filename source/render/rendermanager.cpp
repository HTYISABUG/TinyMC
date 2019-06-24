#include "rendermanager.h"

RenderManager::RenderManager()
{

}

void RenderManager::render(const Camera &camera)
{
    glClearColor(.1f, .5, 1, 1);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // 3D render
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    _quadRenderer.render(camera);
    _cubeRenderer.render(camera);
    _chunkRenderer.render(camera);

    // 2D render
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    _uiRenderer.render();
}

void RenderManager::addQuad(const Vector3 &pos)
{
    _quadRenderer.add(pos);
}

void RenderManager::addCube(const Vector3 &pos)
{
    _cubeRenderer.add(pos);
}

void RenderManager::addChunk(const ChunkMesh &chunkMesh)
{
    _chunkRenderer.add(chunkMesh);
}

void RenderManager::addUi(const ColorMesh &mesh)
{
    _uiRenderer.add(mesh);
}
