#version 330 core
out vec4 FragColor;

in vec4 colourByPos;

void main()
{
    FragColor = vec4((colourByPos +1) / 1.4) ;
}
