#ifndef COLORMODEL2D_H
#define COLORMODEL2D_H

#include "abstractmodel.h"

class ColorModel2D : public AbstractModel
{    
public:
    void addData(const AbstractMesh &mesh);
};

#endif // COLORMODEL2D_H
