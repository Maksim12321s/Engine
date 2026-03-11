#ifndef SHAPE_H
#define SHAPE_H
#include "Matrix.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <vector>
using namespace Vectors;



    class Shape{
        protected:
            Vec3 startCoords;
            Matrix* coords;
            std::vector<unsigned int> order; 
            unsigned int VAO; //общий буффер
            unsigned int VBO; //буффер вершин
            unsigned int EBO; //буффер порядка соединения вершин
            Shape();
            Shape(const Vec3& startCoords);
            virtual void CreateMatrix() = 0;
        public:
            Vec3 GetStartCoords() const;
            Matrix& GetMatrixCoords();
            virtual void draw() = 0;
            ~Shape();
    };


#endif