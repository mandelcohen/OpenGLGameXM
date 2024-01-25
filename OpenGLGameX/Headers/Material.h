#pragma once
#include "glad/glad.h"
#include "Shader.h"

class Material
{
    unsigned int shaderProgram;
public:
    Material(Shader& vertexShader, Shader& fragmentShader){
        unsigned int ShaderProgram { glCreateProgram() };
        glAttachShader(ShaderProgram, vertexShader.shaderId);
        glAttachShader(ShaderProgram, fragmentShader.shaderId);
        glLinkProgram(ShaderProgram);
    }
    
    void use(){
        glUseProgram(shaderProgram);
    }
};
