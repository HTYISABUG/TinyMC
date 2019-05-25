#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <string>
#include <GL/glew.h>

GLuint loadShader(const std::string &vertexShader, const std::string &fragmentShader);

#endif // SHADERLOADER_H
