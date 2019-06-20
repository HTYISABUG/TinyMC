#include "abstractmodel.h"

void AbstractModel::deleteData()
{
    if (_info.vao) {
        glDeleteVertexArrays(1, &_info.vao);
    }

    auto size = _buffers.size();

    if (size > 0) {
        glDeleteBuffers(size, _buffers.data());
    }

    _info.reset();
    _buffers.clear();
    _vboCount = 0;
}

void AbstractModel::genVAO()
{
    if (_info.vao) {
        deleteData();
    }

    glGenVertexArrays(1, &_info.vao);
    bindVAO();
}

void AbstractModel::bindVAO() const
{
    glBindVertexArray(_info.vao);
}

void AbstractModel::addVBO(int dim, const std::vector<GLfloat> &data)
{
    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(_vboCount, dim, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(_vboCount++);

    _buffers.push_back(vbo);
}

void AbstractModel::addEBO(const std::vector<GLuint> &indices)
{
    GLuint ebo;

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    _info.indicesCount = static_cast<GLuint>(indices.size());
}

GLuint AbstractModel::indicesCount() const
{
    return _info.indicesCount;
}
