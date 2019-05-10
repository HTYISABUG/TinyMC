#include "application.h"
#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application(const char *title) :
    context(title)
{

}

int Application::exec()
{
    auto window = context.window();

    do {
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    return EXIT_SUCCESS;
}
