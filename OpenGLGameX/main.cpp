#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Triangle.h"

using namespace std;


int main() {

    Window window {800, 600}; // using window class here
    
    float red {};
    
    float vertices1[] {
        -1.0f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
    };
    
    Mesh mesh1 {vertices1, size(vertices1)};
    
    float vertices2[] {
        -1.0f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
    };
    
    Mesh mesh2 {vertices2, size(vertices2)};
    
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    const char* vertexShaderSource { "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0"}; // the souce explains to the GPU where and what information should go out on the screen

    unsigned int vertexShader { glCreateShader(GL_VERTEX_SHADER) };
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // fragment shader
    const char* OrangeShaderSource { "#version 330 core\n" //orange
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0"}; // gives further information, finds out wat color each pixel should be.
    
    unsigned int OrangeMaterial { glCreateShader(GL_FRAGMENT_SHADER) };
    glShaderSource(OrangeMaterial, 1, &OrangeShaderSource, nullptr);
    glCompileShader(OrangeMaterial); // compile the shader on GPU
    
    unsigned int OrangeShaderProgram { glCreateProgram() };
    glAttachShader(OrangeShaderProgram, vertexShader);
    glAttachShader(OrangeShaderProgram, OrangeMaterial);
    glLinkProgram(OrangeShaderProgram);
    // clean up shaders after they've been linked into a program
    glDeleteShader(vertexShader);
    glDeleteShader(OrangeMaterial);
    
    const char* YellowShaderSource { "#version 330 core\n" // yellow
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0"}; // gives further information, finds out wat color each pixel should be.
    
    unsigned int YellowMaterial { glCreateShader(GL_FRAGMENT_SHADER)};
    glShaderSource(YellowMaterial, 1, &YellowShaderSource, nullptr);
    glCompileShader(YellowMaterial); // compile the shader on GPU
    
    // link shaders, RENDER PIPELINE shader program
    unsigned int YellowShaderProgram { glCreateProgram() };
    glAttachShader(YellowShaderProgram, vertexShader);
    glAttachShader(YellowShaderProgram, YellowMaterial);
    glLinkProgram(YellowShaderProgram);
    // clean up shaders after they've been linked into a program
    glDeleteShader(vertexShader);
    glDeleteShader(YellowMaterial);
    
    // While the User doesn't want to Quit
    while (!window.shouldCLose())
    {   // process input (e.g. close window on ESC)
        window.processInput();
        
        // add variable for colour red
        red += 0.001f;
        if(red > 1)
            red -= 1;
        
        // render (paint the current fram)
        glClearColor(red, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // present
                
        // draw our first triangle
        glUseProgram(OrangeShaderProgram);
        mesh1.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // present (send the current frame to the computer screen)
        window.Present();
    }
    
    // Cleans up all the GLFW stuff
    glfwTerminate();
    
    return 0;
}


