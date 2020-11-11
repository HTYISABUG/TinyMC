#version 330 core

in vec2 passTextureCoord;
out vec4 color;

uniform sampler2D texSampler;

void main()
{
    color = texture2D(texSampler, passTextureCoord);
}
