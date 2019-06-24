#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "renderer/quadrenderer.h"
#include "renderer/cuberenderer.h"
#include "renderer/chunkrenderer.h"
#include "renderer/uirenderer.h"

class Camera;
class ChunkMesh;

class RenderManager
{
public:
    RenderManager();

    void addQuad(const Vector3 &pos);
    void addCube(const Vector3 &pos);
    void addChunk(const ChunkMesh &chunkMesh);
    void addUi(const ColorMesh &mesh);

    void render(const Camera &camera);

private:
    QuadRenderer _quadRenderer;
    CubeRenderer _cubeRenderer;
    ChunkRenderer _chunkRenderer;
    UiRenderer _uiRenderer;
};

#endif // RENDERMANAGER_H
