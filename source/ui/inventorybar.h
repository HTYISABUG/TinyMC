#ifndef INVENTORYBAR_H
#define INVENTORYBAR_H

#include "ui.h"

class InventoryBar : public Ui
{
public:
    static InventoryBar &instance();

    static void scrollCallback(GLFWwindow *, double, double yoffset);

    void setIndicator(double yoffset);

protected:
    void makeMesh();

private:
    InventoryBar();

    unsigned _indicator = 0;
};

#endif // INVENTORYBAR_H
