#include "player.h"
#include "math/glm.h"
#include "math/matrix.h"
#include <GLFW/glfw3.h>

Player::Player(const Vector3 &position, const Vector3 &rotation)
{
    this->position = position;
    this->rotation = rotation;
    this->velocity = Vector3();
}

void Player::handleEvent(GLFWwindow *window)
{
    keyPressEvent(window);
    mouseMoveEvent(window);
}

void Player::update(double delta)
{
    position += velocity * static_cast<float>(delta);
    velocity *= 0.95;
}

void Player::keyPressEvent(GLFWwindow *window)
{
    Vector3 v(0);

    constexpr float speed = 50;

    auto d = glm::normalize(front()) * speed;
    auto r = glm::normalize(right()) * speed;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        v += d;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        v -= d;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        v -= r;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        v += r;
    }

    velocity = v;
}

void Player::mouseMoveEvent(GLFWwindow *window)
{
    static const auto aSpeed = 0.005;

    int x, y;

    glfwGetWindowSize(window, &x, &y);

    Vector2d basePosition, currPosition;

    basePosition = {x, y};
    basePosition /= 2;

    glfwGetCursorPos(window, &currPosition.x, &currPosition.y);

    auto delta = currPosition - basePosition;

    rotation.y += static_cast<float>(-delta.x * aSpeed);
    rotation.x += static_cast<float>(-delta.y * aSpeed);

    static const auto deg90 = glm::radians(90.f);

    if (rotation.x > deg90) {
        rotation.x = deg90;
    } else if (rotation.x < -deg90) {
        rotation.x = -deg90;
    }

    glfwSetCursorPos(window, basePosition.x, basePosition.y);
}
