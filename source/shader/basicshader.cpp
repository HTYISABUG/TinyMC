#include "basicshader.h"

BasicShader::BasicShader(const std::string &vertexFile, const std::string &fragmentFile) :
    AbstractShader(vertexFile, fragmentFile)
{
    getUniforms();
}

void BasicShader::loadProjectionViewMatrix(const Matrix4 &matrix)
{
    loadMatrix(_locationProjectionViewMatrix, matrix);
}

void BasicShader::loadModelMatrix(const Matrix4 &matrix)
{
    loadMatrix(_locationModelMatrix, matrix);
}

void BasicShader::getUniforms()
{
    useProgram();

    auto locationProjectionViewMatrix = glGetUniformLocation(_id, "projectionViewMatrix");
    auto locationModelMatrix = glGetUniformLocation(_id, "modelMatrix");

    if (locationProjectionViewMatrix == -1) {
        throw std::runtime_error("Unable to get uniform location: projectionViewMatrix");
    }

    if (locationModelMatrix == -1) {
        throw std::runtime_error("Unable to get uniform location: modelMatrix");
    }

    _locationProjectionViewMatrix = static_cast<GLuint>(locationProjectionViewMatrix);
    _locationModelMatrix = static_cast<GLuint>(locationModelMatrix);
}
