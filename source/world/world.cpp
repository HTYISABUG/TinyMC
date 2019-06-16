#include "world.h"
#include "render/rendermanager.h"

namespace {
constexpr int WORLD_SIZE = 2;
}

World::World() :
    _chunkManager(this)
{
    for (int z = -1; z < WORLD_SIZE - 1; ++z)
    for (int x = -1; x < WORLD_SIZE - 1; ++x)
    {
        _chunkManager.load({x, z});
    }

    for (auto &[loc, chunk] : _chunkManager.getChunks()) {
        chunk.makeMesh();
    }
}

void World::commitChunks(const Vector3i &blockPosition)
{
    static const auto commit = [this](const VectorXZi &location, Chunk &chunk) {
        _committedChunks.emplace(location, chunk);
    };

    auto chunkLocation = toChunkLocation(blockPosition);

    // commit current chunk
    commit(chunkLocation, _chunkManager.getChunk(chunkLocation));

    auto chunkPosition = toChunkPosition(blockPosition);

    // commit x axis chunk
    if (chunkPosition.x == 0) {
        auto location = chunkLocation.operator-({1, 0});
        commit(location, _chunkManager.getChunk(location));
    } else if (chunkPosition.x == CHUNK_SIZE - 1) {
        auto location = chunkLocation.operator+({1, 0});
        commit(location, _chunkManager.getChunk(location));
    }

    // commit z axis chunk
    if (chunkPosition.z == 0) {
        auto location = chunkLocation.operator-({1, 0});
        commit(location, _chunkManager.getChunk(location));
    } else if (chunkPosition.z == CHUNK_SIZE - 1) {
        auto location = chunkLocation.operator+({1, 0});
        commit(location, _chunkManager.getChunk(location));
    }
}

void World::updateChunks()
{
    for (auto &[loc, chunk] : _committedChunks) {
        chunk.makeMesh();
    }

    _committedChunks.clear();
}

void World::updateRenderer(RenderManager &renderManager)
{
    for (auto &[loc, chunk] : _chunkManager.getChunks()) {
        if (chunk.hasMesh()) {
            renderManager.addChunk(chunk.chunkMesh());
        }
    }
}

ChunkBlock World::getBlock(const Vector3i &position)
{
    auto loc = toChunkLocation(position);
    auto pos = toChunkPosition(position);

    return _chunkManager.getChunk(loc).getBlock(pos);
}

void World::setBlock(const Vector3i &position, const ChunkBlock &block)
{
    if (position.y < 0) {
        return;
    }

    auto loc = toChunkLocation(position);
    auto pos = toChunkPosition(position);

    _chunkManager.getChunk(loc).setBlock(pos, block);
}

void World::updateBlock(const Vector3i &position, const ChunkBlock &block)
{
    setBlock(position, block);

    commitChunks(position);
}

VectorXZi World::toChunkLocation(const Vector3i &position)
{
    return {
        position.x >> 4,
        position.z >> 4,
    };
}

Vector3i World::toChunkPosition(const Vector3i &position)
{
    return {
        position.x & 0xf,
        position.y,
        position.z & 0xf,
    };
}
