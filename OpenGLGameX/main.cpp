#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Triangle.h"
#include "Shader.h"

using namespace std;


int main() {

    Window window {800, 600};
    
    float vertices1[] {
        -1.0f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
    };
    Mesh mesh1 {vertices1, size(vertices1)};
    
    float vertices2[] {
         0.0f, -0.5f, 0.0f,
         1.0f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
    };
    Mesh mesh2 {vertices2, size(vertices2)};
    
    Shader vertexShader {"#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0", GL_VERTEX_SHADER};
    
    Shader orangeShader {"#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0", GL_FRAGMENT_SHADER};
    
    Shader yellowShader {"#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0", GL_FRAGMENT_SHADER};

    Material orange {vertexShader, orangeShader};
    
    Material yellow {vertexShader, yellowShader};
    
    Triangle a {&mesh1, &orange};
    Triangle b {&mesh2, &yellow};
    
    while (!window.shouldCLose())
    {
        window.processInput();
        window.clear();
                
        a.render();
        b.render();
        
        window.Present();
    }
    
    glfwTerminate();
    
    return 0;
}


