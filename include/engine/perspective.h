#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H
#include "Matrix.h"
#include "math.h"
using namespace Vectors;
namespace Vision{
    Matrix CreatePerspective(int height, int width, double f, double n, double alpha);
}

#endif