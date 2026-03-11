#include "engine/engine.h"
#include "shapes/sphere.h"

using namespace shapes;

Engine::Engine(unsigned int height, unsigned int width, GLFWwindow* window) : height(height), width(width), window(window){

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);

    ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram,vertexShader);
    glAttachShader(ShaderProgram,fragmentShader);
    glLinkProgram(ShaderProgram);
    glUseProgram(ShaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Engine::RunEngine(){
    Sphere a(Vec3(0.0,0.0,0.0),1000,0.5);
    while(!glfwWindowShouldClose(window))
    {   
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        a.draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}