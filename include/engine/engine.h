#ifndef ENGINE_H
#define ENGINE_H
#include "glad/gl.h"
#include "GLFW/glfw3.h"

class Engine{
    const char* vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "out vec4 vertexColor;"
                                 "uniform mat4 projection;\n"
                                 "uniform mat4 camera;\n"
                                 "void main(){\n"
                                 "gl_Position = projection*camera*vec4(aPos,1.0);"
                                 "vertexColor = vec4(1.0, 0.0, 0.0, 1.0);"
                                 "}\0";
    const char* fragmentShaderSource = "#version 330 core\n"
                                 "out vec4 FragColor;\n"
                                 "in vec4 vertexColor;\n"
                                 "void main(){\n"
                                 "FragColor = vertexColor;"
                                 "}\0";

    int height;
    int width;
    unsigned int fragmentShader;
    unsigned int vertexShader;
    unsigned int ShaderProgram;
    GLFWwindow* window;
    
    // virtual void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    public:
        void RunEngine();
        Engine(unsigned int height, unsigned int width, GLFWwindow * window);
        void setNewSize(unsigned int,unsigned int);
    
};

#endif