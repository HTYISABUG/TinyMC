#ifndef BASICSHADER_H
#define BASICSHADER_H

#include "abstractshader.h"

class BasicShader : public AbstractShader
{
public:
    BasicShader(const std::string vertexFile = "basic.vert",
                const std::string fragmentFile = "basic.frag");

    void loadProjectionViewMatrix(const Matrix4 &matrix);
    void loadModelMatrix(const Matrix4 &matrix);

private:
    void getUniforms() override;

    GLuint _locationProjectionViewMatrix;
    GLuint _locationModelMatrix;
};

#endif // BASICSHADER_H
