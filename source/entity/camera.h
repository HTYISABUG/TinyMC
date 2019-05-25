#ifndef CAMERA_H
#define CAMERA_H

#include "entity.h"
#include "math/glm.h"

class Camera : private Entity
{
public:
    Camera(const Vector3 &position = Vector3(), const Vector3 &rotation = Vector3());

    bool attachEntity(const Entity &entity);
    void detachEntity();

    Vector3 position() const;
    Vector3 rotation() const;

    Matrix4 projectionMatrix() const;
    Matrix4 viewMatrix() const;
    Matrix4 projectionViewMatrix() const;

private:
    const Entity *_hookEntity;

    Matrix4 _projectionMatrix;
    Matrix4 _viewMatrix;
    Matrix4 _projectionViewMatrix;
};

#endif // CAMERA_H
