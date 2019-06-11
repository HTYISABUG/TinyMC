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
    static bool accelerated = false;

    constexpr float acRate = 2;
    constexpr float hSpeed = 50;
    constexpr float vSpeed = hSpeed;

    Vector3 v(0);

    static const auto pressed = [window](int key) {
        return glfwGetKey(window, key) == GLFW_PRESS;
    };

    static const auto dimReduct = [](const Vector3 &vec) {
        return glm::normalize(Vector3(vec.x, 0, vec.z));
    };

    auto d = dimReduct(front()) * hSpeed;
    auto r = dimReduct(right()) * hSpeed;

    // vertical speed
    if (pressed(GLFW_KEY_SPACE)) {
        v.y += vSpeed;
    }
    if (pressed(GLFW_KEY_LEFT_SHIFT)) {
        v.y -= vSpeed;
    }

    // speed down
    if (!(velocity.x < -hSpeed || hSpeed > velocity.x || velocity.z < -hSpeed || hSpeed > velocity.z)) {
        accelerated = false;
    }

    // speed up
    if (pressed(GLFW_KEY_LEFT_CONTROL)) {
        accelerated = true;
    }
    if (accelerated) {
        d *= acRate;
        r *= acRate;
    }

    // horizontal speed
    if (pressed(GLFW_KEY_W)) {
        v += d;
    }
    if (pressed(GLFW_KEY_S)) {
        v -= d;
    }
    if (pressed(GLFW_KEY_A)) {
        v -= r;
    }
    if (pressed(GLFW_KEY_D)) {
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

    static const auto deg89 = glm::radians(89.f);

    if (rotation.x > deg89) {
        rotation.x = deg89;
    } else if (rotation.x < -deg89) {
        rotation.x = -deg89;
    }

    glfwSetCursorPos(window, basePosition.x, basePosition.y);
}
