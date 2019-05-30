#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>

struct Mesh
{
    std::vector<GLfloat> vertexPositions;
    std::vector<GLfloat> textureCoords;
    std::vector<GLuint>  indices;

    void clear()
    {
        vertexPositions.clear();
        vertexPositions.shrink_to_fit();

        textureCoords.clear();
        textureCoords.shrink_to_fit();

        indices.clear();
        indices.shrink_to_fit();
    }
};

#endif // MESH_H
