#ifndef APPLICATION_H
#define APPLICATION_H

#include "context.h"

class Application
{
public:
    Application(const char *title);

    int exec();

private:
    Context context;
};

#endif // APPLICATION_H
