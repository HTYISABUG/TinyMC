#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "renderer/quadrenderer.h"
#include "renderer/cuberenderer.h"
#include "renderer/chunkrenderer.h"

class Camera;
class ChunkMesh;

class RenderManager
{
public:
    RenderManager();

    void addQuad(const Vector3 &pos);
    void addCube(const Vector3 &pos);
    void addChunk(const ChunkMesh &chunkMesh);

    void render(const Camera &camera);

private:
    QuadRenderer _quadRenderer;
    CubeRenderer _cubeRenderer;
    ChunkRenderer _chunkRenderer;
};

#endif // RENDERMANAGER_H
