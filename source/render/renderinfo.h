#ifndef RENDERINFO_H
#define RENDERINFO_H

#include <GL/glew.h>

struct RenderInfo {
    GLuint vao = 0;
    GLuint indicesCount = 0;

    void reset() {
        vao = 0;
        indicesCount = 0;
    }
};

#endif // RENDERINFO_H
