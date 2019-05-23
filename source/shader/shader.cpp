#include "shader.h"
#include "shaderloader.h"

Shader::Shader(const std::string &vertexFile, const std::string &fragmentFile) :
    _id(loadShader(vertexFile, fragmentFile))
{
    useProgram();
}

Shader::~Shader()
{
    glDeleteProgram(_id);
}

void Shader::loadInt(GLuint location, int value)
{
    glUniform1i(location, value);
}

void Shader::loadFloat(GLuint location, float value)
{
    glUniform1f(location, value);
}

void Shader::loadVector(GLuint location, const Vector2 &vec)
{
    glUniform2f(location, vec.x, vec.y);
}

void Shader::loadVector(GLuint location, const Vector3 &vec)
{
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void Shader::loadVector(GLuint location, const Vector4 &vec)
{
    glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}

void Shader::loadMatrix(GLuint location, const Matrix4 &mat)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::useProgram() const
{
    glUseProgram(_id);
}
