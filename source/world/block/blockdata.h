#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include "math/glm.h"
#include <boost/utility.hpp>

struct BlockData : public boost::noncopyable
{
    BlockData(const std::string &file);

    Vector2i texTopCoord;
    Vector2i texSideCoord;
    Vector2i texBottomCoord;
};

#endif // BLOCKDATA_H
