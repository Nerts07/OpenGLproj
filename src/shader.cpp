#include "shaders.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Shaders::Shaders(const char* vertexPath, const char* fragmentPath)
{
    this->vertexPath = vertexPath;
	this->fragmentPath = fragmentPath;


    this->shaderProgram = (GLuint) nullptr;
}

string loadShaderFile(const char* filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "F errr cannot open file " << filepath << std::endl;
        return "";
    }
    std::stringstream buff;
    buff << file.rdbuf();
    return buff.str();
}

GLuint Shaders::shaderCode() 
{
    string vertexCode = loadShaderFile(vertexPath);
    string fragmentCode = loadShaderFile(fragmentPath);

    const char* vertexShaderSource = vertexCode.c_str();
    const char* fragmentShaderSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void Shaders::useProgram()
{

    glUseProgram(shaderProgram);
}

void Shaders::setInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}