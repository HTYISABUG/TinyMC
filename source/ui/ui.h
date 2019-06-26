#ifndef UI_H
#define UI_H

#include "render/model/colormodel2d.h"

struct GLFWwindow;

class Ui
{
public:
    virtual ~Ui() = default;

    virtual void handleEvent(GLFWwindow *window);

    const ColorModel2D &model() const;

protected:
    virtual void makeMesh() = 0;

    ColorModel2D _model;
};

#endif // UI_H
