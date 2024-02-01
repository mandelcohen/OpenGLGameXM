#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "Window.h"
#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Triangle.h"
#include "Texture.h"

using namespace std;

int main() {
    
    Window window {800, 600};
        
    Texture pattern { "container.jpg", GL_TEXTURE0};
    Texture swirl { "swirl.jpg", GL_TEXTURE1};

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
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Colour::red,       Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{ 0.5f, -0.5f, 0.0f},   Colour::green,     Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Colour::blue,      Vector2{0.0f, 0.0f}},   // bottom left
        Vertex{Vector3{-0.5f,  0.5f, 0.0f},   Colour::yellow,    Vector2{0.0f, 1.0f}},   // top left
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Colour::red,       Vector2{1.0f, 1.0f}},
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Colour::blue,      Vector2{0.0f, 0.0f}}
    };
    
    Mesh mesh4 { vertices4, size(vertices4) };
    
    Vertex vertices5[]{
        // positions                         // colors          // texture coords
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Colour::red,       Vector2{1.0f, 1.0f}},   // top right
        Vertex{Vector3{ 0.5f, -0.5f, 0.0f},   Colour::green,     Vector2{1.0f, 0.0f}},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Colour::blue,      Vector2{0.0f, 0.0f}},   // bottom left
        Vertex{Vector3{-0.5f,  0.5f, 0.0f},   Colour::yellow,    Vector2{0.0f, 1.0f}},   // top left
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},   Colour::red,       Vector2{1.0f, 1.0f}},
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},   Colour::blue,      Vector2{0.0f, 0.0f}}
    };
    
    Mesh mesh5 { vertices5, size(vertices5) };
    
    
    Shader vertexShader {"vertexShader.glsl", GL_VERTEX_SHADER};
    
    Shader vertexAttributes {"vertexAttributes.glsl", GL_VERTEX_SHADER};
    
    Shader textureV {"textureVS.glsl", GL_VERTEX_SHADER};
    
    
    Shader orangeShader {"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader yellowShader {"yellowFragmentShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader rainbowShader {"rainbowShader.glsl", GL_FRAGMENT_SHADER};
    
    Shader uniformShader {"UniformShader.glsl", GL_FRAGMENT_SHADER};

    Shader attributesShader{"fragmentAttributes.glsl", GL_FRAGMENT_SHADER};
    
    Shader textureF {"blendTexFS.glsl", GL_FRAGMENT_SHADER};
    
    
    Material orange {vertexShader, orangeShader};
    
    Material yellow {vertexShader, yellowShader};
    
    Material rainbow {vertexShader, rainbowShader};
    
    Material uniform {vertexShader, uniformShader};
    
    Material withAttributes {vertexAttributes, attributesShader};
    
    Material texMaterial {textureV, textureF};
    
    
    Triangle a {&mesh1, &rainbow};
    a.red = 1; a.green = 0; a.blue = 0; a.offset = 0.2;
    
    Triangle b {&mesh2, &rainbow};
    b.red = 0; b.green = 1; b.blue = 0; b.offset = 0;
    
    Triangle c {&mesh3, &rainbow};
    
    Triangle d {&mesh4, &texMaterial, &swirl};
    d.offset = -0.5f;
    
    Triangle e {&mesh5, &texMaterial, &pattern};
    e.offset = 0.5f;

//    Render only outlines
//    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    
    
    while (!window.shouldCLose())
    {
        window.processInput();
        window.clear();
                
//        a.Render();
//        b.Render();
//        c.Render();
        
//        float timeValue = glfwGetTime();
//        float time = (cos(timeValue));
//        d.offset = time;
        
        d.Render();
        e.Render();
        
        window.Present();
    }
    
    glfwTerminate();
    
    return 0;
}


