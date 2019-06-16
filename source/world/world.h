#ifndef WORLD_H
#define WORLD_H

#include "math/types.h"
#include "chunk/chunkmanager.h"
#include <boost/utility.hpp>

class RenderManager;

class World : public boost::noncopyable
{
public:
    World();

    void commitChunks(const Vector3i &blockPosition); // commit changed chunks to buffer

    void updateChunks();
    void updateRenderer(RenderManager &renderManager);

    ChunkBlock getBlock(const Vector3i &position);
    void setBlock(const Vector3i &position, const ChunkBlock &block);
    void updateBlock(const Vector3i &position, const ChunkBlock &block);

private:
    static VectorXZi toChunkLocation(const Vector3i &position);
    static Vector3i  toChunkPosition(const Vector3i &position);

    ChunkManager _chunkManager;

    std::unordered_map<VectorXZi, Chunk &> _committedChunks;
};

#endif // WORLD_H
