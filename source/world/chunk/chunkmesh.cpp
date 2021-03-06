#include "chunkmesh.h"
#include "chunk.h"
#include "constant.h"
#include "world/block/blockmanager.h"

void ChunkMesh::addSurface(const std::array<GLfloat, 12> &vertexPositions,
                           const std::array<GLfloat,  8> &textureCoords,
                           const VectorXZi &chunkLocation,
                           const Vector3i  &blockPosition)
{
    auto &verticies = _mesh.vertexPositions;
    auto &texCoords = _mesh.textureCoords;
    auto &indices   = _mesh.indices;

    texCoords.insert(texCoords.end(), textureCoords.begin(), textureCoords.end());

    for (unsigned i = 0, index = 0; i < 4; ++i) {
        verticies.push_back(vertexPositions[index++] + chunkLocation.x * CHUNK_SIZE + blockPosition.x);
        verticies.push_back(vertexPositions[index++] + blockPosition.y);
        verticies.push_back(vertexPositions[index++] + chunkLocation.z * CHUNK_SIZE + blockPosition.z);
    }

    indices.insert(indices.end(), {
                       _indexCount, _indexCount + 1, _indexCount + 2,
                       _indexCount + 2, _indexCount + 3, _indexCount,
                   });

    _indexCount += 4;
}

void ChunkMesh::bufferMesh()
{
    _model.addData(_mesh);
    _mesh.clear();

    _indexCount = 0;
}

const TextureModel3D &ChunkMesh::model() const
{
    return _model;
}

namespace {
struct AdjacentPositions
{
    Vector3i front;
    Vector3i back;
    Vector3i right;
    Vector3i left;
    Vector3i top;
    Vector3i bottom;

    void update(const Vector3i &position)
    {
        auto &x = position.x;
        auto &y = position.y;
        auto &z = position.z;

        front  = {x, y, z + 1};
        back   = {x, y, z - 1};
        right  = {x + 1, y, z};
        left   = {x - 1, y, z};
        top    = {x, y + 1, z};
        bottom = {x, y - 1, z};
    }
};
}

ChunkMesh::Builder::Builder(const Chunk &chunk, ChunkMesh &chunkMesh) :
    _chunk(chunk),
    _chunkMesh(chunkMesh)
{

}

void ChunkMesh::Builder::build()
{
    AdjacentPositions adjacPositions;

    for (int y = 0; y < CHUNK_HEIGHT; ++y)
    for (int z = 0; z < CHUNK_SIZE; ++z)
    for (int x = 0; x < CHUNK_SIZE; ++x)
    {
        auto position = Vector3i(x, y, z);
        auto block = _chunk.getBlock(position);

        if (block == BlockId::AIR) {
            continue;
        }

        const auto &data = block.getData();

        adjacPositions.update(position);

        addSurface(CUBE_FRONT_VERTEX_POSITION,  data.texSideCoord, position, adjacPositions.front);
        addSurface(CUBE_BACK_VERTEX_POSITION,   data.texSideCoord, position, adjacPositions.back);
        addSurface(CUBE_RIGHT_VERTEX_POSITION,  data.texSideCoord, position, adjacPositions.right);
        addSurface(CUBE_LEFT_VERTEX_POSITION,   data.texSideCoord, position, adjacPositions.left);

        addSurface(CUBE_TOP_VERTEX_POSITION,    data.texTopCoord,    position, adjacPositions.top);
        addSurface(CUBE_BOTTOM_VERTEX_POSITION, data.texBottomCoord, position, adjacPositions.bottom);
    }
}

void ChunkMesh::Builder::addSurface(const std::array<GLfloat, 12> &vertexPositions,
                                    const Vector2i &atlasLocation,
                                    const Vector3i &blockPosition,
                                    const Vector3i &adjacPosition)
{
    if (_chunk.getBlock(adjacPosition) == BlockId::AIR) {
        auto texCoords = BlockManager::instance().textureAtlas().getTexture(atlasLocation);
        _chunkMesh.addSurface(vertexPositions, texCoords, _chunk.location(), blockPosition);
    }
}
