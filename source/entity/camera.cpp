#include "camera.h"
#include "math/matrix.h"

Camera::Camera(const Vector3 &position, const Vector3 &rotation)
{
    this->position = position;
    this->rotation = rotation;

    _projectionMatrix = makeProjectionMatrix(45);
    _viewMatrix = makeViewMatrix(*this);
    _projectionViewMatrix = _projectionMatrix * _viewMatrix;
}

bool Camera::attachEntity(const Entity &entity)
{
    if (_hookEntity != nullptr) {
        return false;
    } else {
        _hookEntity = &entity;
        return true;
    }
}

void Camera::detachEntity()
{
    _hookEntity = nullptr;
}

void Camera::update()
{
    if (_hookEntity != nullptr) {
        position = _hookEntity->position;
        rotation = _hookEntity->rotation;

        _viewMatrix = makeViewMatrix(*this);
        _projectionViewMatrix = _projectionMatrix * _viewMatrix;
    }
}

Matrix4 Camera::projectionMatrix() const
{
    return _projectionMatrix;
}

Matrix4 Camera::viewMatrix() const
{
    return _viewMatrix;
}

Matrix4 Camera::projectionViewMatrix() const
{
    return _projectionViewMatrix;
}
