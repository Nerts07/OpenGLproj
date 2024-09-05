#include "resources.h"


//GLuint VAO, VBO;

Resources::Resources()
{
    this->VAO = (GLuint)nullptr;
    this->VBO = (GLuint)nullptr;
    this->EBO = (GLuint)nullptr;
    this->colorVBO = (GLuint)nullptr;

    this->tex = nullptr;
}

void Resources::VOS()
{
    tex = make_unique<Textures>(RESOURCES_PATH "grass.png");

    tex->initTex();

    GLfloat vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    };
    GLfloat colours[] = {
      1.0f, 0.0f,  0.0f,
      0.0f, 1.0f,  0.0f,
      0.0f, 0.0f,  1.0f
    };

    GLuint indices[] = {  // we begin with 0
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };


    glGenVertexArrays(1, &VAO); //generate VAO
    glBindVertexArray(VAO);


    glGenBuffers(1, &VBO); //generate VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copy data


    glGenBuffers(1, &EBO); //generate EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0); //interpretate vertex 
    glEnableVertexAttribArray(0);

    //colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*) (3 * sizeof (GLfloat))); //interpretate vertex 
    glEnableVertexAttribArray(1);    
    
    //texture coords
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*) (6 * sizeof (GLfloat))); //interpretate vertex 
    glEnableVertexAttribArray(2);


    glBindVertexArray(0); //free space
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    // 
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //debug mode for polygons

}

void Resources::Draw()
{

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex->texture);

    glBindVertexArray(VAO);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void Resources::dispose()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
