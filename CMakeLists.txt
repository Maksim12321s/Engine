cmake_minimum_required(VERSION 3.10)

project(Engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MATRIX_PROJECT_DIR "/home/maksim/MyIdeas/Matrix")
add_subdirectory(${MATRIX_PROJECT_DIR} ${CMAKE_BINARY_DIR}/build_matrix)
include_directories("${MATRIX_PROJECT_DIR}/include")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)




add_library(glad STATIC src/gl.c)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)


add_library(vision STATIC src/vision.cpp)
target_include_directories(vision PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(vision PRIVATE matrix)

add_library(engineEnv STATIC src/engine.cpp)
target_include_directories(engineEnv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(engineEnv PRIVATE matrix vision)

add_library(shapes STATIC src/shape.cpp src/sphere.cpp)
target_include_directories(shapes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(shapes PRIVATE matrix vector)




add_executable(engine main.cpp src/gl.c)

target_link_libraries(
    engine 
    PRIVATE
    matrix
    vector
    glad
    engineEnv
    glfw
    OpenGL
    shapes
    vision
   
)
