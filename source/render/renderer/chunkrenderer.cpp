#include "chunkrenderer.h"
#include "entity/camera.h"
#include "world/chunk/chunkmesh.h"
#include "world/block/blockmanager.h"

void ChunkRenderer::add(const ChunkMesh &chunkMesh)
{
    _chunks.push_back(&chunkMesh);
}

void ChunkRenderer::render(const Camera &camera)
{
    _shader.useProgram();
    BlockManager::instance().textureAtlas().bindTexture();

    _shader.loadProjectionViewMatrix(camera.projectionViewMatrix());

    for (const auto chunkMesh : _chunks) {
        chunkMesh->model().bindVAO();
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(chunkMesh->model().indicesCount()), GL_UNSIGNED_INT, nullptr);
    }

    _chunks.clear();
}
