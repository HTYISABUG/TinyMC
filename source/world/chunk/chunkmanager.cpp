#include "chunkmanager.h"
#include "chunk.h"
#include <utility>

ChunkManager::ChunkManager(World *world) :
    _world(world)
{

}

void ChunkManager::load(const VectorXZi &location)
{
    getChunk(location).load();
}

Chunk &ChunkManager::getChunk(const VectorXZi &location)
{
    if (!chunkExistAt(location)) {
        _chunks.try_emplace(location, _world, location);
    }

    return _chunks[location];
}

ChunkTable &ChunkManager::getChunks()
{
    return _chunks;
}

bool ChunkManager::chunkExistAt(const VectorXZi &location) const
{
    return _chunks.find(location) != _chunks.end();
}
