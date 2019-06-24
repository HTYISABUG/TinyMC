#ifndef UISHADER_H
#define UISHADER_H

#include "abstractshader.h"

class UiShader : public AbstractShader
{
public:
    UiShader(const std::string &vertexFile = "ui.vert",
             const std::string &fragmentFile = "ui.frag");

    void loadProjectionMatrix(const Matrix4 &matrix);

protected:
    void getUniforms();

private:
    GLuint _locationProjectionMatrix;
};

#endif // UISHADER_H
