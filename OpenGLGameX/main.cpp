#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Triangle.h"

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
    
    Shader vertexShader {"vertexShader.glsl", GL_VERTEX_SHADER};
    
    Shader orangeShader {"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader yellowShader {"yellowFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader rainbowShader {"rainbowShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader uniformShader {"UniformShader.glsl", GL_FRAGMENT_SHADER};

    Material orange {vertexShader, orangeShader};
    
    Material yellow {vertexShader, yellowShader};
    
    Material rainbow {vertexShader, rainbowShader};
    
    Material uniform {vertexShader, uniformShader};
    
    Triangle a {&mesh1, &uniform};
    a.red = 1; a.green = 0; a.blue = 0;
    Triangle b {&mesh2, &uniform};
    b.red = 0; b.green = 1; b.blue = 0;
    
    while (!window.shouldCLose())
    {
        window.processInput();
        window.clear();
                
        a.Render();
        b.Render();
        
        window.Present();
    }
    
    glfwTerminate();
    
    return 0;
}


