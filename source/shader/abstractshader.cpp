#include "abstractshader.h"
#include "shaderloader.h"

AbstractShader::AbstractShader(const std::string &vertexFile, const std::string &fragmentFile) :
    _id(loadShader(vertexFile, fragmentFile))
{
    useProgram();
}

AbstractShader::~AbstractShader()
{
    glDeleteProgram(_id);
}

void AbstractShader::loadInt(GLuint location, int value)
{
    glUniform1i(location, value);
}

void AbstractShader::loadFloat(GLuint location, float value)
{
    glUniform1f(location, value);
}

void AbstractShader::loadVector(GLuint location, const Vector2 &vec)
{
    glUniform2f(location, vec.x, vec.y);
}

void AbstractShader::loadVector(GLuint location, const Vector3 &vec)
{
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void AbstractShader::loadVector(GLuint location, const Vector4 &vec)
{
    glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

void AbstractShader::loadMatrix(GLuint location, const Matrix4 &mat)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void AbstractShader::useProgram() const
{
    glUseProgram(_id);
}
