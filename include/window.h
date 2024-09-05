#include "gladDeclaration.h"


class Window {
public:
	Window(int width, int height, const char* title);
	~Window();
	void centerWindow(GLFWwindow* window);
	void swapBuf();
	void init();
	int getWid();
	int getHei();
	int isShouldClose();
	GLFWwindow* getWindow();
	
private:
	int width;
	int height;
	const char* title;
	GLFWwindow* window;
};