//#version 330 core
//
//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 colorVec;
//
////out vec3 colour;
//out vec4 vertexColor;
//
//void main()
//{
//	//colour = colorVec;
//	gl_Position = vec4(position.x, position.y, position.z, 1.0f);
//	vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
//}

#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord);
}