#ifndef CONTEXT_H
#define CONTEXT_H

struct GLFWwindow;

class Context
{
public:
    Context(const char *title);
    ~Context();

    GLFWwindow *window() const;

private:
    GLFWwindow *_window;
};

#endif // CONTEXT_H
