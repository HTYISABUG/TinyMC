#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>

struct Mesh
{
    std::vector<GLfloat> vertexPosition;
    std::vector<GLfloat> textureCoords;
    std::vector<GLuint>  indices;
};

#endif // MESH_H
