#include "application.h"
#include <cstdlib>
#include <GLFW/glfw3.h>

Application::Application(const char *title) :
    context(title),
    player(&world, {0, 10, 0}, {glm::radians(-20.), glm::radians(0.), glm::radians(0.)})
{

}

int Application::exec()
{
    auto window = context.window();

    camera.attachEntity(player);
    manager.addUi({
        {0, 0, 0, 100, 100, 100, 100, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 2, 2, 3, 0},
    });

    do {
        auto ts = glfwGetTime();

        glfwPollEvents();
        player.handleEvent(window);

        player.update(glfwGetTime() - ts);
        world.updateChunks();
        camera.update();

        world.updateRenderer(manager);
        manager.render(camera);

        glfwSwapBuffers(window);
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    return EXIT_SUCCESS;
}
