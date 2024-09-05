#include "window.h"

#include <iostream>

//GLFWwindow* window = nullptr;

Window::Window(int width, int height, const char* title)
{
	this->width = width;
	this->height = height;
	this->title = title;
    this->window = nullptr;
}
void resizeWindowCallback(GLFWwindow* window, int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
}
void Window::init()
{
    glfwInit();
    window = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;

    }    
    
    
    glfwSetFramebufferSizeCallback(window, resizeWindowCallback);
    //glfwGetFramebufferSize(window, &width, &height);
    //glViewport(0, 0, width, height);

}
Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}



void Window::centerWindow(GLFWwindow* window)
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* winMode = glfwGetVideoMode(monitor);

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    int xPos = (winMode->width - windowWidth) / 2;
    int yPos = (winMode->height - windowHeight) / 2;

    glfwSetWindowPos(window, xPos, yPos);
}

void Window::swapBuf()
{
    glfwSwapBuffers(window);
}
int Window::getWid()
{
    return width;
}
int Window::getHei()
{
    return height;
}

int Window::isShouldClose()
{
    return glfwWindowShouldClose(window);
}

GLFWwindow* Window::getWindow()
{
    return window;
}