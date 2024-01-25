#pragma once

class Material{
    unsigned int shaderProgram;
public:
    Material(const char* shaderSource){
        // do all of the loading code
    }
    
    void Activate(){
        glUseProgram(shaderProgram);
    }
};
