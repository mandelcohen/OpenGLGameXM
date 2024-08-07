#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "glad/glad.h"

class Shader
{
    std::string readShaderFile(const std::string& filePath) {
        std::ifstream fileStream(filePath);

        if (!fileStream.is_open()) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return "";
        }

        std::stringstream buffer;
        buffer << fileStream.rdbuf();
        return buffer.str();
    }

    // Function to compile a shader from a source file
    GLuint compileShaderFromFile(const std::string& filePath, GLenum shaderType) {
        // Read shader source code from the file
        std::string shaderSource = readShaderFile(filePath);
        if (shaderSource.empty()) {
            return 0; // Failed to read shader source
        }
        
        const GLchar* shaderSourcePtr = shaderSource.c_str();
        
        // Compile shader
        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSourcePtr, nullptr);
        glCompileShader(shader);
        
        // Check for compilation errors
        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        
        if (!success) {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader compilation error in " << filePath << ":\n" << infoLog << std::endl;
            glDeleteShader(shader);
            return 0;
        }
        
        return shader;
    }
    
public:
    unsigned int shaderId;
    Shader(const char* source, int shaderType){ // when constructed: load shader on GPU
        shaderId = compileShaderFromFile(source, shaderType);
    }
    Shader(const Shader&) = delete; // avoid it being cloned

    ~Shader() { // when destructed: delete the shader from GPU
        glDeleteShader(shaderId);
    }
};
