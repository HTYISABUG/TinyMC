#ifndef TEXTUREATLAS_H
#define TEXTUREATLAS_H

#include "basictexture.h"
#include "math/glm.h"
#include <array>

class TextureAtlas : public BasicTexture
{
public:
    TextureAtlas(const std::string &file);

    std::array<GLfloat, 8> getTexture(const Vector2 &coords) const;

private:
    int _width, _height;
    int _tWidth, _tHeight;
};

#endif // TEXTUREATLAS_H
