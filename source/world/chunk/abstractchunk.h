#ifndef ABSTRACTCHUNK_H
#define ABSTRACTCHUNK_H

#include "math/types.h"

class ChunkBlock;

struct AbstractChunk
{
    virtual ~AbstractChunk() = default;

    virtual ChunkBlock getBlock(const Vector3i &position) const = 0;
    virtual void setBlock(const Vector3i &position, const ChunkBlock &block) = 0;
};

#endif // ABSTRACTCHUNK_H
