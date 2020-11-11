#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec2 textureCoord;

out vec2 passTextureCoord;

uniform mat4 projectionViewMatrix;

void main()
{
    gl_Position = projectionViewMatrix * vec4(vertexPosition, 1.0);
    passTextureCoord = textureCoord;
}
