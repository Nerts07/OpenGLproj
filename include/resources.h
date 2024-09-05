#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>
#include <memory>
#include "textures.h"

using namespace std;

class Resources {
public:
	Resources();

	void VOS();
	void Draw();
	void dispose();
	
private:
	GLuint VAO, VBO;
	GLuint EBO;
	GLuint colorVBO;

	unique_ptr<Textures> tex;
};