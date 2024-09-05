//#version 330 core
//
//out vec4 FragColor;
//in vec4 vertexColor;
//
//void main()
//{
//	//FragColor = vec4(0.5f, 1.0f, 0.5f, 0.5f);
//	//FragColor = vec4(0.5, 0.0, 0.0, 1.0);
//	FragColor = vertexColor;
//	//FragColor = vec4(vertexColor, 1.0f);
//}
//

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
}