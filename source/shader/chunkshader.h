#ifndef CHUNKSHADER_H
#define CHUNKSHADER_H

#include "abstractshader.h"

class ChunkShader : public AbstractShader
{
public:
    ChunkShader(const std::string vertexFile = "chunk.vert",
                const std::string fragmentFile = "chunk.frag");

    void loadProjectionViewMatrix(const Matrix4 &matrix);

private:
    void getUniforms() override;

    GLuint _locationProjectionViewMatrix;
};

#endif // CHUNKSHADER_H
