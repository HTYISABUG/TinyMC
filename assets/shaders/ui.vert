#version 330 core

layout (location = 0) in vec2 vertexLocation;
layout (location = 1) in vec4 fragmentColor;

out vec4 passColor;

uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix * vec4(vertexLocation, 0.0, 1.0);
    passColor = fragmentColor;
}
