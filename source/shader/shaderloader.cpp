#include "shaderloader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <boost/filesystem.hpp>

#define MAX_LENGTH 512

using namespace std;

namespace {
    string getFileContents(const string &path)
    {
        ifstream file(path);
        stringstream ss;

        if (!file.is_open()) {
            throw runtime_error("Unable to open file: " + path);
        }

        ss << file.rdbuf();

        return ss.str();
    }

    GLuint compileShader(const GLchar *source, GLenum shaderType)
    {
        auto shaderID = glCreateShader(shaderType);

        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);

        GLint status = 0;
        GLchar infoLog[MAX_LENGTH];

        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &status);

        if (status != 0) {
            glGetShaderInfoLog(shaderID, MAX_LENGTH, nullptr, infoLog);
            throw runtime_error("Unable to load shader: " + string(infoLog));
        }

        return shaderID;
    }

    GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
    {
        auto id = glCreateProgram();

        glAttachShader(id, vertexShaderID);
        glAttachShader(id, fragmentShaderID);
        glLinkProgram(id);

        return id;
    }
}

GLuint loadShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    namespace fs = boost::filesystem;

    auto prefix = fs::path("res/shader");

    auto vertexSource = getFileContents((prefix / vertexShader).string());
    auto fragmentSource = getFileContents((prefix / fragmentShader).string());

    auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
    auto fragmentShaderID = compileShader(vertexSource.c_str(), GL_FRAGMENT_SHADER);

    auto programID = linkProgram(vertexShaderID, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return programID;
}
