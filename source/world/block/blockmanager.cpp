#include "blockmanager.h"

const BlockManager &BlockManager::instance()
{
    static BlockManager manager;
    return manager;
}

const Block &BlockManager::getBlock(BlockId id) const
{
    return *_blocks[static_cast<unsigned>(id)];
}

const BlockData &BlockManager::getData(BlockId id) const
{
    return getBlock(id).data();
}

const TextureAtlas &BlockManager::textureAtlas() const
{
    return _textureAtlas;
}

BlockManager::BlockManager() :
    _textureAtlas("texture_atlas.png")
{
    _blocks[static_cast<unsigned>(BlockId::AIR)]         = std::make_unique<Block>("air.json");
    _blocks[static_cast<unsigned>(BlockId::DIRT)]        = std::make_unique<Block>("dirt.json");
    _blocks[static_cast<unsigned>(BlockId::GRASS)]       = std::make_unique<Block>("grass.json");
    _blocks[static_cast<unsigned>(BlockId::STONE)]       = std::make_unique<Block>("stone.json");
    _blocks[static_cast<unsigned>(BlockId::COBBLESTONE)] = std::make_unique<Block>("cobblestone.json");
}
