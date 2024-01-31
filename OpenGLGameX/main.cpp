#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Triangle.h"
#include "stb_image.h"

using namespace std;



int main() {
    
    Window window {800, 600};
    
//    texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    
    
    Vertex vertices1[] {
        Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
        Vertex{Vector3{ 0.0f, -0.5f, 0.0f}},
        Vertex{Vector3{-0.5f,  0.5f, 0.0f}}
    };
    
    Mesh mesh1 { vertices1, size(vertices1) };
    
    Vertex vertices2[] {
        Vertex{Vector3{0.0f, -0.5f, 0.0f}},
        Vertex{Vector3{1.0f, -0.5f, 0.0f}},
        Vertex{Vector3{0.5f,  0.5f, 0.0f}}
    };
    
    Mesh mesh2 {vertices2, size(vertices2)};
    
    Vertex vertices3[] = {
        Vertex{Vector3{0.5f, -0.5f, 0.0f}, Colour::red},
        Vertex{Vector3{-0.5f, -0.5f, 0.0}, Colour::green},
        Vertex{Vector3{0.0f,  0.5f, 0.0f}, Colour::blue}
    };
    
    Mesh mesh3 {vertices3, size(vertices3)};
    
    Vertex vertices4[]{
        // positions                         // colors          // texture coords
        Vertex{Vector3{0.5f,  0.5f, 0.0f},   Colour::red,       Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{0.5f, -0.5f, 0.0f},   Colour::green,     Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{0.5f, -0.5f, 0.0f},   Colour::blue,      Vector2{0.0f, 0.0f}},   // bottom left
        Vertex{Vector3{0.5f,  0.5f, 0.0f},   Colour::yellow,    Vector2{0.0f, 1.0f}}    // top left
    };
    
    Mesh mesh4 {vertices4, size(vertices4)};
    
    
    Shader vertexShader {"vertexShader.glsl", GL_VERTEX_SHADER};
    
    Shader vertexAttributes {"vertexAttributes.glsl", GL_VERTEX_SHADER};
    
    Shader textureV {"textureVS.glsl", GL_VERTEX_SHADER};
    
    
    Shader orangeShader {"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader yellowShader {"yellowFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader rainbowShader {"rainbowShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader uniformShader {"UniformShader.glsl", GL_FRAGMENT_SHADER};

    Shader attributesShader{"fragmentAttributes.glsl", GL_FRAGMENT_SHADER};
    
    Shader textureF {"textureFS.glsl", GL_FRAGMENT_SHADER};
    
    
    Material orange {vertexShader, orangeShader};
    
    Material yellow {vertexShader, yellowShader};
    
    Material rainbow {vertexShader, rainbowShader};
    
    Material uniform {vertexShader, uniformShader};
    
    Material withAttributes {vertexAttributes, attributesShader};
    
    Material texture1 {textureV, textureF};
    
    
    Triangle a {&mesh1, &rainbow};
    a.red = 1; a.green = 0; a.blue = 0; a.offset = 0.2;
    
    Triangle b {&mesh2, &rainbow};
    b.red = 0; b.green = 1; b.blue = 0; b.offset = 0;
    
    Triangle c {&mesh3, &rainbow};
    
    Triangle d {&mesh4, &rainbow};
    
//    Render only outlines
//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    
    
    while (!window.shouldCLose())
    {
        window.processInput();
        window.clear();
                
//        a.Render();
//        b.Render();
//        c.Render();
        d.Render();
        window.Present();
    }
    
    glfwTerminate();
    
    return 0;
}


