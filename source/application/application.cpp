#include "application.h"
#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application(const char *title) :
    context(title),
    camera({5, 0, 5}, {glm::radians(0.), glm::radians(45.), glm::radians(45.)})
{

}

int Application::exec()
{
    auto window = context.window();

    glEnable(GL_DEPTH_TEST);

    do {
        manager.render(camera);

        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    return EXIT_SUCCESS;
}
