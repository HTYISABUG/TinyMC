#ifndef CHUNKMESH_H
#define CHUNKMESH_H

#include "math/types.h"
#include "render/mesh.h"
#include "render/model.h"
#include <array>

class ChunkMesh
{
public:
    void addSurface(const std::array<GLfloat, 12> &vertexPositions,
                    const std::array<GLfloat,  8> &textureCoords,
                    const VectorXZi &chunkLocation,
                    const Vector3i  &blockPosition);
    void bufferMesh();

    const Model &model() const;

    class Builder;

private:
    Mesh  _mesh;
    Model _model;

    GLuint _indexCount = 0;
};

class Chunk;
class BlockData;

class ChunkMesh::Builder
{
public:
    Builder(const Chunk &chunk, ChunkMesh &chunkMesh);

    void build();

private:
    void addSurface(const std::array<GLfloat, 12> &vertexPositions,
                    const Vector2i &atlasLocation,
                    const Vector3i &blockPosition,
                    const Vector3i &adjacPosition);

    const Chunk &_chunk;
    ChunkMesh &_chunkMesh;
};

#endif // CHUNKMESH_H