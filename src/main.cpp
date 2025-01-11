#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width,height);
}

void inputProcessing(GLFWwindow *window) {
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main() {
    //Initialise GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Create the GLFW window for the application
    GLFWwindow* digCreateWindow = glfwCreateWindow(1080, 720, "Dig Create", NULL, NULL);
    if(digCreateWindow == NULL) {
        std::cout << "The Window Didnt Create (GLFW's Fault, Not Mine)" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Make the window context current so it opens in front of other apps
    glfwMakeContextCurrent(digCreateWindow);

    //Initialise GLAD
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to do the GLAD stuff" << std::endl;
        return -1;
    }
    //Creates The Viewport For The Application
    glViewport(0,0,1080,720);

    //Frame Buffer Size Callback (Basically Should Resize The Window)
    glfwSetFramebufferSizeCallback(digCreateWindow, framebuffer_size_callback);

    //Run whilst app is open
    while(!glfwWindowShouldClose(digCreateWindow)) {

        //Input Processing
        inputProcessing(digCreateWindow);

        //Clear Background
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Frame Buffer Swap
        glfwSwapBuffers(digCreateWindow);

        //IDK TBH LearnOpenGL Said To Put It Here
        glfwPollEvents();
    }

    glfwDestroyWindow(digCreateWindow);
    glfwTerminate();
    return 0;
}
