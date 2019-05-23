#ifndef APPLICATION_H
#define APPLICATION_H

#include "context.h"
#include "../render/rendermanager.h"
#include "../entity/camera.h"

class Application
{
public:
    Application(const char *title);

    int exec();

private:
    Context context;
    RenderManager manager;
    Camera camera;
};

#endif // APPLICATION_H
