#pragma once

#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>

class Shaders {
public:
	Shaders(const char* vertexPath, const char* fragmentPath);
	GLuint shaderCode();
	void useProgram();
	void setInt(const std::string& name, int value) const;
	GLuint shaderProgram;
private:
	const char* vertexPath;
	const char* fragmentPath;

	
};

