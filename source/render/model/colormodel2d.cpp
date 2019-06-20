#include "colormodel2d.h"
#include "render/mesh.h"

void ColorModel2D::addData(const AbstractMesh &mesh)
{
    auto colorMesh = dynamic_cast<const ColorMesh &>(mesh);

    genVAO();
    addVBO(2, colorMesh.vertexPositions);
    addVBO(3, colorMesh.vertexColors);
    addEBO(colorMesh.indices);
}
