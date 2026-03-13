#ifndef CAMERA_H
#define CAMERA_H
#include "Matrix.h"
using namespace Vectors;

namespace Vision{

    class Camera{
        Vec3 Position;
        Vec3 Direction;
        Vec3 UpVector;
        double yaw;
        double pitch;
        float cameraSpeed = 0.1;
        public:
            Camera(Vec3 startCoords,Vec3 dir, Vec3 up);
            Matrix CreateLookAt();
            void CameraMove(char d);
            void TurnCamera(double dx, double dy);
            
    };
}


#endif