#ifndef BASICTEXTURE_H
#define BASICTEXTURE_H

#include <boost/utility.hpp>
#include <GL/glew.h>

namespace cv {
    class Mat;
}

class BasicTexture : public boost::noncopyable
{
public:
    BasicTexture() = default;
    BasicTexture(const std::string &file);
    ~BasicTexture();

    void bindTexture() const;

    void loadFromFile(const std::string &file);

protected:
    cv::Mat loadImage(const std::string &file);
    void loadFromImage(const cv::Mat &image);

private:
    GLuint _id;
};

#endif // BASICTEXTURE_H
