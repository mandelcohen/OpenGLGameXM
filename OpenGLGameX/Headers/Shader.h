#pragma once

#include "glad/glad.h"

class Shader
{
public:
    unsigned int shaderId;
    Shader() { // when constructed: load shader on GPU
        const char* vertexShaderSource{ "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0" };
        shaderId = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(shaderId, 1, &vertexShaderSource, nullptr);
        glCompileShader(shaderId);
    }
    Shader(const Shader&) = delete; // avoid it being cloned

    ~Shader() { // when destructed: delete the shader from GPU
        glDeleteShader(shaderId);
    }
};
