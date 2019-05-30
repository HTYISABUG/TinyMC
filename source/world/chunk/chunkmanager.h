#ifndef CHUNKMANAGER_H
#define CHUNKMANAGER_H

#include "math/vectorxz.h"
#include "chunk.h"
#include <unordered_map>

using ChunkTable = std::unordered_map<VectorXZi, Chunk>;

class ChunkManager
{
public:
    Chunk &getChunk(const VectorXZi &location);
    ChunkTable &getChunks();

private:
    bool chunkExistAt(const VectorXZi &location) const;

    ChunkTable _chunks;
};

#endif // CHUNKMANAGER_H
