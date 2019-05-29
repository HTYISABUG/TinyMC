#ifndef CHUNKBLOCK_H
#define CHUNKBLOCK_H

#include "world/block/blockid.h"

class Block;
class BlockData;

// a helper struct for chunk to save block
struct ChunkBlock
{
public:
    ChunkBlock() = default;
    ChunkBlock(Block_t id);
    ChunkBlock(BlockId id);

    const Block &getBlock() const;
    const BlockData &getData() const;

    bool operator==(ChunkBlock other)
    {
        return id == other.id;
    }

    bool operator!=(ChunkBlock other)
    {
        return id != other.id;
    }

    Block_t id = 0;
};

#endif // CHUNKBLOCK_H
