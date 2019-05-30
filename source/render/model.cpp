#include "model.h"
#include "mesh.h"

Model::Model(const Mesh &mesh)
{
    addData(mesh);
}

void Model::addData(const Mesh &mesh)
{
    genVAO();
    addVBO(3, mesh.vertexPositions);
    addVBO(2, mesh.textureCoords);
    addEBO(mesh.indices);
}

void Model::deleteData()
{
    if (_renderInfo.vao) {
        glDeleteVertexArrays(1, &_renderInfo.vao);
    }

    auto size = _buffers.size();

    if (size > 0) {
        glDeleteBuffers(size, _buffers.data());
    }

    _renderInfo.reset();
    _buffers.clear();
    _vboCount = 0;
}

void Model::genVAO()
{
    if (_renderInfo.vao) {
        deleteData();
    }

    glGenVertexArrays(1, &_renderInfo.vao);
    bindVAO();
}

void Model::bindVAO() const
{
    glBindVertexArray(_renderInfo.vao);
}

void Model::addVBO(int dim, const std::vector<GLfloat> &data)
{
    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(_vboCount, dim, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(_vboCount++);

    _buffers.push_back(vbo);
}

void Model::addEBO(const std::vector<GLuint> &indices)
{
    GLuint ebo;

    _renderInfo.indicesCount = static_cast<GLuint>(indices.size());

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

GLuint Model::indicesCount() const
{
    return _renderInfo.indicesCount;
}

const RenderInfo &Model::renderInfo() const
{
    return _renderInfo;
}
