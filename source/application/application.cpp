#include "application.h"
#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application(const char *title) :
    context(title),
    camera(Vector3(-3), {glm::radians(-35.), glm::radians(45. + 180), glm::radians(0.)})
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
