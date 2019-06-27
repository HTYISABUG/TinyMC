#ifndef CONSTANT_H
#define CONSTANT_H

#include <array>
#include <vector>
#include <GL/glew.h>

constexpr int WINDOW_WIDTH = 1280,
              WINDOW_HEIGHT = 720;

constexpr int CHUNK_SIZE = 16,
              CHUNK_HEIGHT = 256,
              CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE,
              CHUNK_VOLUME = CHUNK_HEIGHT * CHUNK_AREA;

constexpr int INVENTORY_NUM = 9,
              INVENTORY_BLOCK_SIZE = 64,
              INVENTORY_BORDER_SIZE = 8,
              INVENTORY_ITEM_SIZE = 24;

const std::array<GLfloat, 12> CUBE_FRONT_VERTEX_POSITION = {
    -0.5,  0.5,  0.5,
    -0.5, -0.5,  0.5,
    0.5, -0.5,  0.5,
    0.5,  0.5,  0.5,
};

const std::array<GLfloat, 12> CUBE_BACK_VERTEX_POSITION = {
    0.5,  0.5, -0.5,
    0.5, -0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,
};

const std::array<GLfloat, 12> CUBE_RIGHT_VERTEX_POSITION = {
    0.5,  0.5,  0.5,
    0.5, -0.5,  0.5,
    0.5, -0.5, -0.5,
    0.5,  0.5, -0.5,
};

const std::array<GLfloat, 12> CUBE_LEFT_VERTEX_POSITION = {
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5, -0.5,  0.5,
    -0.5,  0.5,  0.5,
};

const std::array<GLfloat, 12> CUBE_TOP_VERTEX_POSITION = {
    -0.5,  0.5, -0.5,
    -0.5,  0.5,  0.5,
    0.5,  0.5,  0.5,
    0.5,  0.5, -0.5,
};

const std::array<GLfloat, 12> CUBE_BOTTOM_VERTEX_POSITION = {
    -0.5, -0.5,  0.5,
    -0.5, -0.5, -0.5,
    0.5, -0.5, -0.5,
    0.5, -0.5,  0.5,
};

const std::vector<GLfloat> CUBE_VERTEX_POSITION = []() {
    std::vector<GLfloat> v;

    v.insert(v.end(), CUBE_FRONT_VERTEX_POSITION.begin(),   CUBE_FRONT_VERTEX_POSITION.end());
    v.insert(v.end(), CUBE_BACK_VERTEX_POSITION.begin(),    CUBE_BACK_VERTEX_POSITION.end());
    v.insert(v.end(), CUBE_RIGHT_VERTEX_POSITION.begin(),   CUBE_RIGHT_VERTEX_POSITION.end());
    v.insert(v.end(), CUBE_LEFT_VERTEX_POSITION.begin(),    CUBE_LEFT_VERTEX_POSITION.end());
    v.insert(v.end(), CUBE_TOP_VERTEX_POSITION.begin(),     CUBE_TOP_VERTEX_POSITION.end());
    v.insert(v.end(), CUBE_BOTTOM_VERTEX_POSITION.begin(),  CUBE_BOTTOM_VERTEX_POSITION.end());

    return v;
}();

const std::vector<GLuint> CUBE_INDICES = {
    // front
    0, 1, 2,
    2, 3, 0,

    // back
    4, 5, 6,
    6, 7, 4,

    // right
    8, 9, 10,
    10, 11, 8,

    // left
    12, 13, 14,
    14, 15, 12,

    // top
    16, 17, 18,
    18, 19, 16,

    // bottom
    20, 21, 22,
    22, 23, 20,
};

#endif // CONSTANT_H
