#version 330 core
out vec4 FragColor;
  
in vec4 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D blendTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
//    FragColor = mix(texture(ourTexture, TexCoord), texture(blendTexture, TexCoord), 0.5);
}
