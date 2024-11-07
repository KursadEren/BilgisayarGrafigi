#version 330 core
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inTexCoord;

uniform vec3 uMove;
out vec2 TexCoord;
void main()
{
    vec3 worldPosition = inPosition + uMove;
    gl_Position = vec4(worldPosition, 1.0);

    TexCoord = inTexCoord;
}