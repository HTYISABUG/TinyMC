#ifndef CONSTANT_H
#define CONSTANT_H

constexpr int WINDOW_WIDTH = 1280,
              WINDOW_HEIGHT = 720;

constexpr int CHUNK_SIZE = 16,
              CHUNK_HEIGHT = 256,
              CHUNK_AREA = CHUNK_SIZE * CHUNK_SIZE,
              CHUNK_VOLUME = CHUNK_HEIGHT * CHUNK_AREA;

#endif // CONSTANT_H
