#include "engine/engine.h"
#include "shapes/sphere.h"
#include "engine/perspective.h"
#include "Matrix.h"
#include "engine/camera.h"

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
    Sphere a(Vec3(0.0,0.0,-5.0),100,0.5);
    glUseProgram(ShaderProgram);
    Vec3 pos(0,0,-3);
    Vec3 direction(0,0,1);
    Vec3 up(0,1,0);
    Vision::Camera camera(pos,direction,up);
    
    while(!glfwWindowShouldClose(window))
    {   
    
        glfwGetWindowSize(window, &width, &height);
        if(glfwGetKey(window,GLFW_KEY_W) == GLFW_PRESS){
            camera.CameraMove('w');
        }
        if(glfwGetKey(window,GLFW_KEY_S) == GLFW_PRESS){
            camera.CameraMove('s');
        }
        if(glfwGetKey(window,GLFW_KEY_A) == GLFW_PRESS){
            camera.CameraMove('a');
        }
        if(glfwGetKey(window,GLFW_KEY_D) == GLFW_PRESS){
            camera.CameraMove('d');
        }
        Vectors::Matrix LookAt = camera.CreateLookAt();
        int cameraLoc = glGetUniformLocation(ShaderProgram, "camera");
        glUniformMatrix4fv(cameraLoc, 1, GL_TRUE, LookAt.getData());


        Vectors::Matrix projMatrix = Vision::CreatePerspective(height, width, 100.0, 0.1, 45.0);
        int projectionLoc = glGetUniformLocation(ShaderProgram, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projMatrix.getData());

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        a.draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::setNewSize(unsigned int h, unsigned int w){
    height = h;
    width = w;
}