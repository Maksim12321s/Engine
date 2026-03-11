// все классы фигур добавить в одно поле имен 
#ifndef SPHERE_H
#define SPHERE_H
#include "shapes/shape.h"
#include "Matrix.h"
namespace shapes{
    class Sphere: public Shape{
        double r;
        unsigned int accuracy;
        public:
            Sphere(const Vec3&,unsigned int acc, double r);
            void draw() override;
            void CreateMatrix() override;
            ~Sphere();
    };
};
#endif