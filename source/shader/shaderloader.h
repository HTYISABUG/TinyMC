#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <GL/glew.h>
#include <string>

GLuint loadShader(const std::string &vertexShader, const std::string &fragmentShader);

#endif // SHADERLOADER_H
