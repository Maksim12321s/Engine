#ifndef CAMERA_H
#define CAMERA_H
#include "Matrix.h"
using namespace Vectors;

namespace Vision{

    class Camera{
        Vec3 Position;
        Vec3 Direction;
        Vec3 UpVector;
        float cameraSpeed = 0.1;
        public:
            Camera(Vec3 startCoords,Vec3 dir, Vec3 up);
            Matrix CreateLookAt();
            void CameraMove(char d);
            
    };
}


#endif