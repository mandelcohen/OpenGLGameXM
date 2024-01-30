#pragma once
#include <cstddef>
#include "glad/glad.h"

struct Vector3 {
    float x, y, z;
};

struct Colour {
    static const Colour red;
    static const Colour green;
    static const Colour blue;
    
    float r, g, b, a;
};


struct Vertex {
    Vector3 pos;
    Colour col{1, 1, 1, 1};
};

class Mesh
{
    unsigned int VAO;
    size_t vertexCount;
    
public:
    
    void Render(){
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }
    
    Mesh(Vertex* vertices, size_t count){
        vertexCount = count;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * count, vertices, GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
        glEnableVertexAttribArray(0);
        
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, col));
        glEnableVertexAttribArray(1);
    }
};
