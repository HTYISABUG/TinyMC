#include "chunkblock.h"
#include "blockmanager.h"

ChunkBlock::ChunkBlock(Block_t id) :
    id(id)
{

}

ChunkBlock::ChunkBlock(BlockId id) :
    id(static_cast<Block_t>(id))
{

}

const Block &ChunkBlock::getBlock() const
{
    return BlockManager::instance().getBlock(static_cast<BlockId>(id));
}

const BlockData &ChunkBlock::getData() const
{
    return getBlock().data();
}
