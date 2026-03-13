#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "engine/engine.h"
#define WIDTH 1600
#define HEIGHT 600
const char* name = "Engine";


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    
}
int main(){
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIDTH,HEIGHT,name,NULL,NULL);
    if(window ==NULL){
        std::cout << "Window didnt created :((";
        glfwTerminate();
        return -1;
    }
    

    glfwMakeContextCurrent(window);

    if (!gladLoaderLoadGL())
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0,0,WIDTH,HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (glfwRawMouseMotionSupported()) {
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
    }
    glfwSetCursorPos(window,WIDTH/2,HEIGHT/2);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Engine engine(HEIGHT,WIDTH,window);
    engine.RunEngine();

    

    glfwTerminate();
    return 0;
}