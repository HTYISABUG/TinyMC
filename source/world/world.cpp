#include "world.h"

ChunkBlock World::getBlock(const Vector3i &position)
{
    auto loc = toChunkLocation(position);
    auto pos = toChunkPosition(position);
    return _chunkManager.getChunk(loc).getBlock(pos);
}

void World::setBlock(const Vector3i &position, const ChunkBlock &block)
{
    if (position.y < 0) {
        return;
    }

    auto loc = toChunkLocation(position);
    auto pos = toChunkPosition(position);

    _chunkManager.getChunk(loc).setBlock(pos, block);
}

VectorXZi World::toChunkLocation(const Vector3i &position)
{
    return {
        position.x >> 4,
        position.z >> 4,
    };
}

Vector3i World::toChunkPosition(const Vector3i &position)
{
    return {
        position.x & 0xf,
        position.y,
        position.z & 0xf,
    };
}
