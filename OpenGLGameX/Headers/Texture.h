#pragma once
#include <iostream>
#include "glad/glad.h"
#include "stb_image.h"
using namespace std;

class Texture{
    
public:
    Texture(const char* imagePath, int textureUnit)
    {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
        
        unsigned int textureID;
        glGenTextures(1, &textureID);
        glActiveTexture(textureUnit); // before binding
        glBindTexture(GL_TEXTURE_2D, textureID);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }
};
