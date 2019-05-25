#ifndef APPLICATION_H
#define APPLICATION_H

#include "context.h"
#include "entity/camera.h"
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
};

#endif // APPLICATION_H
