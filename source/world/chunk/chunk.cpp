#include "chunk.h"

Chunk::Chunk(const VectorXZi &location) :
    _location(location)
{
    for (int y = 0; y < CHUNK_HEIGHT; ++y)
    for (int z = 0; z < CHUNK_SIZE; ++z)
    for (int x = 0; x < CHUNK_SIZE; ++x)
    {
        if (y == 4) {
            setBlock({x, y, z}, BlockId::GRASS);
        } else if (y == 0) {
            setBlock({x, y, z}, BlockId::STONE);
        } else if (y < 4) {
            setBlock({x, y, z}, BlockId::DIRT);
        }
    }
}

void Chunk::makeMesh()
{
    ChunkMesh::Builder(*this, _mesh).build();
    _mesh.bufferMesh();
}

ChunkBlock Chunk::getBlock(const Vector3i &position) const
{
    if (inRange(position)) {
        return _blocks[getIndex(position)];
    } else {
        // TODO: out of bound handler
    }
}

void Chunk::setBlock(const Vector3i &position, const ChunkBlock &block)
{
    if (inRange(position)) {
        _blocks[getIndex(position)] = block;
    } else {
        // TODO: out of bound handler
    }
}

const VectorXZi &Chunk::location() const
{
    return _location;
}

bool Chunk::inRange(const Vector3i &position)
{
    return !((position.x < 0 || position.x >= CHUNK_SIZE)   ||
             (position.y < 0 || position.y >= CHUNK_HEIGHT) ||
             (position.z < 0 || position.z >= CHUNK_SIZE));
}

unsigned Chunk::getIndex(const Vector3i &position)
{
    return static_cast<unsigned>(
       position.y * CHUNK_AREA +
       position.z * CHUNK_SIZE +
       position.x
    );
}

Vector3i Chunk::toWorldPosition(const Vector3i &position)
{
    return {
        _location.x * CHUNK_SIZE + position.x,
                                   position.y,
        _location.z * CHUNK_SIZE + position.z,
    };
}
