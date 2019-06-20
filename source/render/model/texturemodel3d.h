#ifndef TEXTUREMODEL3D_H
#define TEXTUREMODEL3D_H

#include "abstractmodel.h"

class TextureModel3D : public AbstractModel
{
public:
    void addData(const AbstractMesh &mesh);
};

#endif // TEXTUREMODEL3D_H
