#include "application.h"
#include "ui/inventorybar.h"
#include <cstdlib>
#include <GLFW/glfw3.h>
#include "util.h"

Application::Application(const char *title) :
    context(title),
    player(&world, {0, 10, 0}, {glm::radians(-20.), glm::radians(0.), glm::radians(0.)})
{

}

int Application::exec()
{
    auto window = context.window();

    camera.attachEntity(player);

    glfwSetScrollCallback(window, InventoryBar::scrollCallback);

    do {
        auto ts = glfwGetTime();

        // event handler
        glfwPollEvents();
        player.handleEvent(window);

        // render data update
        player.update(glfwGetTime() - ts);
        world.updateChunks();
        camera.update();

        // renderer update
        world.updateRenderer(manager);

        // ui update
        manager.addUi(InventoryBar::instance());

        // render
        manager.render(camera);

        glfwSwapBuffers(window);
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    return EXIT_SUCCESS;
}
