#ifndef SHADER_H
#define SHADER_H

#include "math/glm.h"
#include <string>
#include <boost/utility.hpp>
#include <GL/glew.h>

class Shader : public boost::noncopyable
{
public:
    Shader(const std::string &vertexFile, const std::string &fragmentFile);
    virtual ~Shader();

    void loadInt(GLuint location, int value);
    void loadFloat(GLuint location, float value);

    void loadVector(GLuint location, const Vector2 &vec);
    void loadVector(GLuint location, const Vector3 &vec);
    void loadVector(GLuint location, const Vector4 &vec);

    void loadMatrix(GLuint location, const Matrix4 &mat);

    void useProgram() const;

protected:
    virtual void getUniforms() = 0;

    GLuint _id;
};

#endif // SHADER_H
