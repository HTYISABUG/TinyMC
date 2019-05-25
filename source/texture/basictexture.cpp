#include "basictexture.h"
#include <stdexcept>
#include <boost/filesystem.hpp>
#include <opencv2/opencv.hpp>

BasicTexture::BasicTexture(const std::string &file)
{
    loadFromFile(file);
}

BasicTexture::~BasicTexture()
{
    glDeleteTextures(1, &_id);
}

void BasicTexture::bindTexture() const
{
    glBindTexture(GL_TEXTURE_2D, _id);
}

void BasicTexture::loadFromFile(const std::string &file)
{
    loadFromImage(loadImage(file));
}

cv::Mat BasicTexture::loadImage(const std::string &file)
{
    namespace fs = boost::filesystem;

    static const auto path = fs::path("assets/textures");

    auto image = cv::imread((path / file).string());

    if (!image.data) {
        throw std::runtime_error("Unable to load image: " + file);
    }

    cv::flip(image, image, 0);

    return image;
}

void BasicTexture::loadFromImage(const cv::Mat &image)
{
    glGenTextures(1, &_id);
    glBindTexture(GL_TEXTURE_2D, _id);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.cols, image.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, image.data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);
}
