//#define GLFW_INCLUDE_NONE
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <cmath>

#include "shaders.h"
#include "resources.h"
#include "window.h"


using namespace std;

void error_callback(int error, const char* description)
{
    std::cerr << "Error: " << description << std::endl;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

GLint width = 800;
GLint height = 600;

int main() 
{
    glfwSetErrorCallback(error_callback);

    Shaders shader (RESOURCES_PATH"vert.glsl", RESOURCES_PATH"frag.glsl");
    //Resources* scr = new Resources();
    //Window* window = new Window(width, height, "Minecraft");


    //unique_ptr<Shaders> shader = make_unique<Shaders>(RESOURCES_PATH"vert.glsl", RESOURCES_PATH"frag.glsl");
    unique_ptr<Resources> scr = make_unique<Resources>();
    unique_ptr<Window> window = make_unique<Window>(width, height, "Minecraft");

    window->init();
    window->centerWindow(window->getWindow());
    
    shader.shaderCode();
    scr->VOS();

    GLuint id = shader.shaderCode();

    glfwSetKeyCallback(window->getWindow(), key_callback);

    while (!window->isShouldClose()) 
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f,0.0f,0.4f,1.0f);

        // Render here

        shader.useProgram();

        scr->Draw();

        // Render here
        

        
        window->swapBuf();
        glfwPollEvents();
    }

    scr->dispose();
    //delete shader;
    //delete scr;
    //delete window;

    return 0;
}