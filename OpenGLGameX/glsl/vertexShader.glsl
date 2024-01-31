#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 colourByPos;
uniform float offsetX;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) + vec4(offsetX, 0, 0, 0);
    
    colourByPos = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
