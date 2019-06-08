#ifndef CAMERA_H
#define CAMERA_H

#include "entity.h"
#include "math/types.h"

class Camera : public Entity
{
public:
    Camera(const Vector3 &position = Vector3(), const Vector3 &rotation = Vector3());

    bool attachEntity(const Entity &Camera);
    void detachEntity();
    void update();

    Matrix4 projectionMatrix() const;
    Matrix4 viewMatrix() const;
    Matrix4 projectionViewMatrix() const;

private:
    const Entity *_hookEntity = nullptr;

    Matrix4 _projectionMatrix;
    Matrix4 _viewMatrix;
    Matrix4 _projectionViewMatrix;
};

#endif // CAMERA_H
