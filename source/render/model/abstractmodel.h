#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include "render/renderinfo.h"
#include <vector>
#include <boost/noncopyable.hpp>

struct AbstractMesh;

class AbstractModel : public boost::noncopyable
{
public:
    virtual ~AbstractModel() = default;

    virtual void addData(const AbstractMesh &mesh) = 0;
    void deleteData();

    void genVAO();
    void bindVAO() const;
    void addVBO(int dim, const std::vector<GLfloat> &data);
    void addEBO(const std::vector<GLuint> &indices);

    GLuint indicesCount() const;

private:
    RenderInfo _info;
    std::vector<GLuint> _buffers;

    int _vboCount = 0;
};

#endif // ABSTRACTMODEL_H
