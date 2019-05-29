#ifndef BLOCK_H
#define BLOCK_H

#include "blockdata.h"
#include <boost/utility.hpp>

class Block : public boost::noncopyable
{
public:
    Block(const std::string &file);

    const BlockData &data() const;

private:
    BlockData _data;
};

#endif // BLOCK_H
