
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Triangle.h"

using namespace std;

void processInput(GLFWwindow*); // forward declaration, defined further down

int main() {

    Window window {800, 600}; // using window class here
    
//    initialisation ends here
//    ========================
//    Real program starts here:
    
    float red {};
    
    // Create array buffer and copy our verticies to GPU
    float Triangle1[] {
        -0.75f, 0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,
        -0.25f, 0.0f, 0.0f,
    };
    float Triangle2[] {
         0.25f, 0.0f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.75f, 0.0f, 0.0f
    };
    
    // class called shader for the shader program
    
    
    unsigned int VBO1, VAO1; // variables to store the buffer IDs
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle1), Triangle1, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    unsigned int VBO2, VAO2; // variables to store the buffer IDs
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle2), Triangle2, GL_STATIC_DRAW);
    
    // configure vertex attributes, so the shader knows wher to find the position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
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
        glfwPollEvents();
        processInput(window.window);
        
        // add variable for colour red
        red += 0.001f;
        if(red > 1)
            red -= 1;
        
        // render (paint the current fram)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // present
                
        // draw our first triangle
        glUseProgram(OrangeShaderProgram);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glUseProgram(YellowShaderProgram);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // present (send the current frame to the computer screen)
        glfwSwapBuffers(window.window);
    }
    
    // Cleans up all the GLFW stuff
    glfwTerminate();
    
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
