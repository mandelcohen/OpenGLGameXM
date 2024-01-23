
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

using namespace std;

void error_callback(int error, const char* msg) {
    cerr << " [" << error << "] " << msg << endl;
}

int main() {

    glfwSetErrorCallback(error_callback);

    // Initialize GLFW
    if (!glfwInit()) { // Exit, if it failed
        cout << "Failed to init GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Request Window from Operating System
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD (connects OpenGL Functions)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        glfwTerminate();
        return -1;
    }
    glViewport(0, 0, 800, 600);

    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window); // ??
        glfwPollEvents();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}
