#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>

struct AbstractMesh
{
    virtual ~AbstractMesh() = default;

    virtual void clear() = 0;

    std::vector<GLfloat>    vertexPositions;
    std::vector<GLuint>     indices;
};

struct ColorMesh : AbstractMesh
{
    ColorMesh() = default;
    ColorMesh(std::vector<GLfloat>  vertexPositions,
              std::vector<GLfloat>  vertexColors,
              std::vector<GLuint>   indices);

    void clear() override;

    std::vector<GLfloat> vertexColors;
};

struct TextureMesh : AbstractMesh
{
    TextureMesh() = default;
    TextureMesh(std::vector<GLfloat>    vertexPositions,
                std::vector<GLfloat>    textureCoords,
                std::vector<GLuint>     indices);

    void clear() override;

    std::vector<GLfloat> textureCoords;
};

#endif // MESH_H
