/* Template for creating a window using OpenGL by using glfw by Josefine Klintberg.
Include frameworks: OpenGL.framework and the file glfw lib that can be downloaded from this folder. 
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//GLFW
#include "glfw3.h"

int main()
{
    //Vertex data
    const GLfloat vertex_array_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    
    
    int width, height;
    const GLFWvidmode *vidmode; //Pointer to a struct that hold information about the display
    GLFWwindow *window; //Pointer to struct that holds window information

    glfwInit(); //Initialize glfw
    vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor()); //Determine the desktop size

    //Make sure we get OpenGL context of at least version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    //Open a window
    window = glfwCreateWindow(600, 600, "OpenGL test", NULL, NULL);
    if(!window){
        glfwTerminate(); //No window was opened so terminate program
        return -1;
    }

    //Make the new window the current context
    glfwMakeContextCurrent(window);

    //Set the viewport
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height); //render to the entire window

    glfwSwapInterval(0); //Do not wait to refresh between frames

    //Rendering loop
    while(!glfwWindowShouldClose(window)){
        //Set the clear color and clear buffer for drawing
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //RENDERING CODE

        //Swap buffers, display the image and prepare for next frame
        glfwSwapBuffers(window);
        glfwPollEvents(); //Poll events, keyboard and mouse input

        //Exit if ESC
        if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }
    
    //Close the OpenGL window, terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}



