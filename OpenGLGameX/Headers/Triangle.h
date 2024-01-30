#pragma once

#include "Material.h"
#include "Mesh.h"


class Triangle{
    Mesh* mesh;
    Material* material;
    
public:
    float red, green, blue;
    
    Triangle(Mesh* _mesh, Material* _material){
        mesh = _mesh;
        material = _material;
    }
    
    void Render(){
        material->Use();
        
        int tintLocation = glGetUniformLocation(material->shaderProgram, "tintColour");
        glUniform4f(tintLocation, red, green, blue, 1);
        
        mesh->Render();
    }
};
