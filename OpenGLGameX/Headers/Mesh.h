#pragma once
#include "glad/glad.h"

class Mesh
{
    unsigned int VAO;
    size_t vertexCount;
    
public:
    
    void Render(){
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }
    
    Mesh(float* vertices, size_t count){
        vertexCount = count / 3;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
};
