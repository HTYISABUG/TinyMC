#include "chunkmanager.h"
#include "chunk.h"

Chunk &ChunkManager::getChunk(const VectorXZi &location)
{
    if (!chunkExistAt(location)) {
        _chunks.emplace(location, location);
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
