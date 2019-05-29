#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include "block.h"
#include "blockid.h"
#include "texture/textureatlas.h"
#include <array>
#include <memory>
#include <boost/utility.hpp>

class BlockManager : public boost::noncopyable
{
public:
    static const BlockManager &instance();

    BlockManager(BlockManager &&) = delete;
    BlockManager &operator=(BlockManager &&) = delete;

    const Block &getBlock(BlockId id) const;
    const BlockData &getData(BlockId id) const;

    const TextureAtlas &textureAtlas() const;

private:
    BlockManager();

    TextureAtlas _textureAtlas;
    std::array<std::unique_ptr<Block>, static_cast<unsigned>(BlockId::NUM_TYPES)> _blocks;
};

#endif // BLOCKMANAGER_H
