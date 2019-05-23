#ifndef BASICSHADER_H
#define BASICSHADER_H

#include "shader.h"

class BasicShader : public Shader
{
public:
    BasicShader(const std::string vertexFile = "BasicVertex.glsl",
                const std::string fragmentFile = "BasicFragment.glsl");

    void loadProjectionViewMatrix(const Matrix4 &matrix);
    void loadModelMatrix(const Matrix4 &matrix);

private:
    void getUniforms() override;

    GLuint _locationProjectionViewMatrix;
    GLuint _locationModelMatrix;
};

#endif // BASICSHADER_H
