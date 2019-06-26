#ifndef CHUNKRENDERER_H
#define CHUNKRENDERER_H

#include "shader/chunkshader.h"
#include <vector>

class ChunkMesh;
class Camera;

class ChunkRenderer
{
public:
    friend class RenderManager;

    void add(const ChunkMesh &chunkMesh);
    void render(const Camera &camera);

private:
    ChunkRenderer() = default;

    std::vector<const ChunkMesh *> _chunks;

    ChunkShader _shader;
};

#endif // CHUNKRENDERER_H
