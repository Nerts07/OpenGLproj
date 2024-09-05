#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image/stb_image.h>
#include <iostream>

#include "shaders.h"

using namespace std;
class Textures {

public:
	Textures(const char* filePath);
	unsigned int texture;
	unsigned int initTex();
private:
	
	unsigned char *data;
	const char* filePath;
	int width, height, nrChannels;

};