#ifndef BLOCKID_H
#define BLOCKID_H

#include <cstdint>

using Block_t = uint8_t;

enum class BlockId : Block_t
{
    AIR = 0,
    DIRT,
    GRASS,
    STONE,
    COBBLESTONE,

    NUM_TYPES
};

#endif // BLOCKID_H
