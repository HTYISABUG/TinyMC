#ifndef BASICTEXTURE_H
#define BASICTEXTURE_H

#include <GL/glew.h>
#include <boost/utility.hpp>

class BasicTexture : public boost::noncopyable
{
public:
    BasicTexture() = default;
    BasicTexture(const std::string &file);
    ~BasicTexture();

    void bindTexture() const;

    void loadFromFile(const std::string &file);

private:
    GLuint _id;
};

#endif // BASICTEXTURE_H
