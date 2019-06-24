#include "chunkshader.h"

ChunkShader::ChunkShader(const std::string &vertexFile, const std::string &fragmentFile) :
    AbstractShader(vertexFile, fragmentFile)
{
    getUniforms();
}

void ChunkShader::loadProjectionViewMatrix(const Matrix4 &matrix)
{
    loadMatrix(_locationProjectionViewMatrix, matrix);
}

void ChunkShader::getUniforms()
{
    useProgram();

    auto locationProjectionViewMatrix = glGetUniformLocation(_id, "projectionViewMatrix");

    if (locationProjectionViewMatrix == -1) {
        throw std::runtime_error("Unable to get uniform location: projectionViewMatrix");
    }

    _locationProjectionViewMatrix = static_cast<GLuint>(locationProjectionViewMatrix);
}
