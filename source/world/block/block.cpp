#include "block.h"

Block::Block(const std::string &file) :
    _data(file)
{

}

const BlockData &Block::data() const
{
    return _data;
}
