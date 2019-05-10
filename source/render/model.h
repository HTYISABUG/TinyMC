#ifndef MODEL_H
#define MODEL_H

#include "renderinfo.h"
#include <vector>
#include <boost/utility.hpp>

struct Mesh;

class Model : public boost::noncopyable
{
public:
    Model() = default;
    Model(const Mesh &mesh);

    void addData(const Mesh &mesh);
    void deleteData();

    void genVAO();
    void bindVAO() const ;
    void addVBO(int dim, const std::vector<GLfloat> &data);
    void addEBO(const std::vector<GLuint> &indices);

    GLuint indicesCount() const;
    const RenderInfo &renderInfo() const;

private:
    RenderInfo _renderInfo;
    std::vector<GLuint> _buffers;

    int _vboCount = 0;
};

#endif // MODEL_H
