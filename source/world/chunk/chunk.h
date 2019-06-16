#ifndef CHUNK_H
#define CHUNK_H

#include "chunkmesh.h"
#include "constant.h"
#include "world/block/chunkblock.h"
#include <array>

class World;

class Chunk
{
public:
    Chunk() = default;
    Chunk(World *world, const VectorXZi &location);

    void load();
    void makeMesh();

    ChunkBlock getBlock(const Vector3i &position) const;
    void setBlock(const Vector3i &position, const ChunkBlock &block);

    const ChunkMesh &chunkMesh() const;
    const VectorXZi &location() const;

    bool hasMesh() const;
    bool isLoaded() const;

private:
    static bool inRange(const Vector3i &position);
    static unsigned getIndex(const Vector3i &position);

    Vector3i toWorldPosition(const Vector3i &position) const;

    World *_world;
    ChunkMesh _chunkMesh;
    VectorXZi _location;
    std::array<ChunkBlock, CHUNK_VOLUME> _blocks;

    bool _hasMesh = false;
    bool _isLoaded = false;
};

#endif // CHUNK_H
