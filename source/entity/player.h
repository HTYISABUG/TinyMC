#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class World;
struct GLFWwindow;

class Player : public Entity
{
public:
    Player(World *world, const Vector3 &position = Vector3(), const Vector3 &rotation = Vector3());

    void handleEvent(GLFWwindow *window);
    void update(double delta);

private:
    void keyPressEvent(GLFWwindow *window);
    void mouseMoveEvent(GLFWwindow *window);
    void mousePressEvent(GLFWwindow *window);

    World *_world;
    Vector3 velocity;
};

#endif // PLAYER_H
