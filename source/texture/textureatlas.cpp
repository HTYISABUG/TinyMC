#include "textureatlas.h"
#include <boost/filesystem.hpp>
#include <opencv2/opencv.hpp>

#define TEXTURE_EDGE 32

TextureAtlas::TextureAtlas(const std::string &file)
{
    auto image = loadImage(file);

    loadFromImage(image);

    _width = image.cols;
    _height = image.rows;
    _tWidth = _tHeight = TEXTURE_EDGE;
}

std::array<GLfloat, 8> TextureAtlas::getTexture(const Vector2 &coords)
{
    static const auto TEXTURE_PER_ROW = static_cast<GLfloat>(_width) / _tWidth;
    static const auto TEXTURE_WIDTH = 1.f / TEXTURE_PER_ROW;
    static const auto PIXEL_WIDTH = 1.f / _width;

    static const auto TEXTURE_PER_COL = static_cast<GLfloat>(_height) / _tHeight;
    static const auto TEXTURE_HEIGHT = 1.f / TEXTURE_PER_COL;
    static const auto PIXEL_HEIGHT = 1.f / _height;

    auto xMin = coords.x * TEXTURE_WIDTH + 0.5f * PIXEL_WIDTH;
    auto yMin = coords.y * TEXTURE_HEIGHT + 0.5f * PIXEL_HEIGHT;

    auto xMax = xMin + TEXTURE_WIDTH - 0.5f * PIXEL_WIDTH;
    auto yMax = yMin + TEXTURE_HEIGHT - 0.5f * PIXEL_HEIGHT;

    yMin = 1.f - yMin;
    yMax = 1.f - yMax;

    return {
        xMin, yMin,
        xMin, yMax,
        xMax, yMax,
        xMax, yMin,
    };
}
