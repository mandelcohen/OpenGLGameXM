#pragma once

#include "Material.h"
#include "Mesh.h"
#include "Texture.h"


class Triangle{
    Mesh* mesh;
    Material* material;
    Texture* texture;
    
public:
    float red, green, blue;
    float offset;
    
    Triangle(Mesh* _mesh, Material* _material, Texture* _texture = nullptr){
        mesh = _mesh;
        material = _material;
        texture = _texture;
    }
    
    void Render(){
        material->Use();
        
        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColour");
        glUniform4f(tintLocation, red, green, blue, 1);
        
        float offsetLocation = glGetUniformLocation(material->shaderProgram, "offsetX");
        glUniform1f(offsetLocation, offset);
        
        int tex1Location = glGetUniformLocation(material->shaderProgram, "ourTexture");
        glUniform1i(tex1Location, 0);
        glActiveTexture(GL_TEXTURE0);
        if (texture != nullptr)
            glBindTexture(GL_TEXTURE_2D, texture->textureID);
        else
            glBindTexture(GL_TEXTURE_2D, 0);
        
        int tex2Location = glGetUniformLocation(material->shaderProgram, "blendTexture");
        glUniform1i(tex2Location, 1);
        
        mesh->Render();
    }
};
