#ifndef APPLICATION_H
#define APPLICATION_H

#include "context.h"
#include "world/world.h"
#include "entity/camera.h"
#include "entity/player.h"
#include "render/rendermanager.h"

class Application
{
public:
    Application(const char *title);

    int exec();

private:
    Context context;
    Camera camera;
    RenderManager manager;

    World world;
    Player player;
};

#endif // APPLICATION_H
