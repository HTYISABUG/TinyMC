#include "application.h"
#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application(const char *title) :
    context(title),
    camera({16.5, 10, 40}, {glm::radians(-20.), glm::radians(0.), glm::radians(0.)})
{

}

int Application::exec()
{
    auto window = context.window();

    do {
        world.updateRenderer(manager);
        manager.render(camera);
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    return EXIT_SUCCESS;
}
