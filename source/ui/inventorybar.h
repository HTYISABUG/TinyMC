#ifndef INVENTORYBAR_H
#define INVENTORYBAR_H

#include "ui.h"
#include "constant.h"
#include "world/block/blockid.h"
#include <array>

class InventoryBar : public Ui
{
public:
    static InventoryBar &instance();

    static void scrollCallback(GLFWwindow *, double, double yoffset);

    BlockId getItem() const;

protected:
    void makeMesh();
    void makeMesh2D();
    void makeMesh3D();

private:
    InventoryBar();

    void setIndicator(double yoffset);

    std::array<BlockId, INVENTORY_NUM> _items;

    unsigned _indicator = 0;
};

#endif // INVENTORYBAR_H
