#pragma once

#include "Material.h"
#include "Mesh.h"


class Triangle{
    Mesh* mesh;
    Material* material;
    
public:
    float red, green, blue;
    float offset;
    
    Triangle(Mesh* _mesh, Material* _material){
        mesh = _mesh;
        material = _material;
    }
    
    void Render(){
        material->Use();
        
        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColour");
        glUniform4f(tintLocation, red, green, blue, 1);
        
        float offsetLocation = glGetUniformLocation(material->shaderProgram, "offsetX");
        glUniform1f(offsetLocation, offset);
        
        int tex1Location = glGetUniformLocation(material->shaderProgram, "ourTexture");
        glUniform1i(tex1Location, 0);
        
        int tex2Location = glGetUniformLocation(material->shaderProgram, "blendTexture");
        glUniform1i(tex2Location, 1);
        
        mesh->Render();
    }
};
