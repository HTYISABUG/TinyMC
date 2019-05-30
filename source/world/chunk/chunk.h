#ifndef CHUNK_H
#define CHUNK_H

#include "abstractchunk.h"
#include "chunkmesh.h"
#include "world/constant.h"
#include "world/block/chunkblock.h"
#include <array>

class Chunk : public AbstractChunk
{
public:
    Chunk(const VectorXZi &location);

    void makeMesh();

    ChunkBlock getBlock(const Vector3i &position) const override;
    void setBlock(const Vector3i &position, const ChunkBlock &block) override;

    const VectorXZi &location() const;

private:
    static bool inRange(const Vector3i &position);
    static unsigned getIndex(const Vector3i &position);

    Vector3i toWorldPosition(const Vector3i &position);

    ChunkMesh _mesh;
    VectorXZi _location;
    std::array<ChunkBlock, CHUNK_VOLUME> _blocks;
};

#endif // CHUNK_H
