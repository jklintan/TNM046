/*OpenGL template in VS that creates a simple window, by Josefine Klintberg
- Make sure to set directories for include, libraries and source files 
	project-> ... properties-> Configuration properties -> VC++ directories
- Download the 32-bit version of glfw (https://www.glfw.org/download.html)
- In project-> ... properties-> Configuration properties -> Linker -> Input
	add opengl32.lib and glfw3.lib in additional dependencies
*/

#include <iostream>

//Include GLFW
#include <GLFW/glfw3.h>

using namespace std;

int main() {

	int width, height;

	//Hold information about the window
	const GLFWvidmode *vidmode;  
	GLFWwindow *window;   

	//Initialise GLFW and error testing
	glfwInit();

	if (!glfwInit()) {
		cout << "Error in setting up GLFW";
		return -1;
	}

	//Determine the desktop size
	vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// Make sure we are getting a GL context of at least version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Open a square window (aspect 1:1) to fill half the screen height
	window = glfwCreateWindow(vidmode->height / 2, vidmode->height / 2, "OpenGL template", NULL, NULL);
	if (!window)
	{
		cout << "Error in window opening!" << endl;
		glfwTerminate(); 
		return -1;
	}

	//Make the window to the current context
	glfwMakeContextCurrent(window);

	// Show some useful information on the GL context
	cout << "GL vendor:       " << glGetString(GL_VENDOR) << endl;
	cout << "GL renderer:     " << glGetString(GL_RENDERER) << endl;
	cout << "GL version:      " << glGetString(GL_VERSION) << endl;
	cout << "Desktop size:    " << vidmode->width << "x" << vidmode->height << " pixels" << endl;

	// Get window size. It may start out different from the requested
	// size, and will change if the user resizes the window.
	glfwGetWindowSize(window, &width, &height);
	
	// Set viewport
	glViewport(0, 0, width, height);

	glfwSwapInterval(0); // Do not wait for screen refresh between frames

	// Rendering loop
	while (!glfwWindowShouldClose(window))
	{
		// Set the clear color and depth, and clear the buffers for drawing
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Swap buffers
		glfwSwapBuffers(window);

		// Check for poll events
		glfwPollEvents();

		// Exit if ESC or closing of window
		if (glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}

	}

	// Close the window and terminate glfw
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}