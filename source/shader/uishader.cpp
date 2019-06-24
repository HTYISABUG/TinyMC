#include "uishader.h"

UiShader::UiShader(const std::string &vertexFile, const std::string &fragmentFile) :
    AbstractShader(vertexFile, fragmentFile)
{
    getUniforms();
}

void UiShader::loadProjectionMatrix(const Matrix4 &matrix)
{
    loadMatrix(_locationProjectionMatrix, matrix);
}

void UiShader::getUniforms()
{
    useProgram();

    auto locationProjectionMatrix = glGetUniformLocation(_id, "projectionMatrix");

    if (locationProjectionMatrix == -1) {
        throw std::runtime_error("Unable to get uniform location: projectionMatrix");
    }

    _locationProjectionMatrix = static_cast<GLuint>(locationProjectionMatrix);
}
