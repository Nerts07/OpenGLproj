#include "textures.h"


Textures::Textures(const char* filePath)
{
	this->filePath = filePath;

	this->width = (int)nullptr;
	this->height = (int)nullptr;
	this->nrChannels = (int) nullptr;
	this->texture = (unsigned int) nullptr;
	this->data = nullptr;

	//this->shaders = nullptr;
}

unsigned int Textures::initTex()
{

	Shaders shader(RESOURCES_PATH"vert.glsl", RESOURCES_PATH"frag.glsl");

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//Wrapping and filters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	data = stbi_load(filePath, &width, &height, &nrChannels, 0);


	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		std::cout << "texture loaded" << std::endl;
	}
	else
	{
		std::cout << "failed to load texture" << std::endl;
	}
	
	stbi_image_free(data);

	//GLuint id = shader.shaderCode();
	//glUniform1i(glGetUniformLocation(id, "texture1"), 0);
	//shader.setInt("texture2", 1);

	return texture;
}