#version 330 core
out vec4 FragColor;
  
uniform vec4 tintColour; // we set this variable in the main through the data members of class triangle.

void main()
{
    FragColor = tintColour;
}
