#include "texturemodel3d.h"
#include "render/mesh.h"

void TextureModel3D::addData(const AbstractMesh &mesh)
{
    auto textureMesh = dynamic_cast<const TextureMesh &>(mesh);

    genVAO();
    addVBO(3, textureMesh.vertexPositions);
    addVBO(2, textureMesh.textureCoords);
    addEBO(textureMesh.indices);
}
