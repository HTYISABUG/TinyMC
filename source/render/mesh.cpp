#include "mesh.h"

ColorMesh::ColorMesh(std::vector<GLfloat> vertexPositions, std::vector<GLfloat> vertexColors, std::vector<GLuint> indices)
{
    this->vertexPositions = vertexPositions;
    this->vertexColors = vertexColors;
    this->indices = indices;
}

void ColorMesh::clear()
{
    vertexPositions.clear();
    vertexPositions.shrink_to_fit();

    indices.clear();
    indices.shrink_to_fit();

    vertexColors.clear();
    vertexColors.shrink_to_fit();
}

TextureMesh::TextureMesh(std::vector<GLfloat> vertexPositions, std::vector<GLfloat> textureCoords, std::vector<GLuint> indices)
{
    this->vertexPositions = vertexPositions;
    this->textureCoords = textureCoords;
    this->indices = indices;
}

void TextureMesh::clear()
{
    vertexPositions.clear();
    vertexPositions.shrink_to_fit();

    indices.clear();
    indices.shrink_to_fit();

    textureCoords.clear();
    textureCoords.shrink_to_fit();
}
