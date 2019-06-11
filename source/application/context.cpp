#include "context.h"
#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WIDTH 1280
#define HEIGHT 720

Context::Context(const char *title)
{
    using namespace std;

    if (glfwInit() != GLFW_TRUE) {
        throw runtime_error("Unable to initial GLFW");
    }

    // setup glfw window
    glfwWindowHint(GLFW_SAMPLES, 4); // antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use core profile

    _window = glfwCreateWindow(WIDTH, HEIGHT, title, nullptr, nullptr);

    glfwMakeContextCurrent(_window);
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    auto err = glewInit();

    if (err != GLEW_OK) {
        glfwTerminate();
        throw runtime_error(reinterpret_cast<const char *>(glewGetErrorString(err)));
    }
}

Context::~Context()
{
    glfwDestroyWindow(_window);
}

GLFWwindow *Context::window() const
{
    return _window;
}
