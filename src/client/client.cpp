#include <iostream>

#include <GLFW/glfw3.h>


int main(int argc, const char **argv)
{
	GLFWwindow *window = nullptr;

	std::cout << "hello world!" << std::endl;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(414, 896, "canvas!!!", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(window);

}


