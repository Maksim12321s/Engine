#include "engine/perspective.h"
#include "engine/camera.h"
#include "vector"
#include "iostream"



Matrix Vision::CreatePerspective(int height, int width, double f, double n, double alpha){
    Matrix perspective(4,4);
    double rads = alpha*M_PI/180;
    double aspect = (double)width/height;
    perspective[0] = 1/(tan(rads/2)*aspect);
    perspective[5] = 1/tan(rads/2);
    perspective[10] = -(f + n)/(f - n);
    perspective[11] = -1;
    perspective[14] = -2*f*n/(f - n);


    return perspective;
}


Matrix Vision::Camera::CreateLookAt(){
    
    
    Vec3 right = Cross(Direction,UpVector).normalize();
    Vec3 up = Cross(Direction,right).normalize();

    float tx = -(Position.x * right.x + Position.y * right.y + Position.z * right.z);
    float ty = -(Position.x * up.x    + Position.y * up.y    + Position.z * up.z);
    float tz =  (Position.x * Direction.x + Position.y * Direction.y + Position.z * Direction.z);

    std::vector<float> a = {
        right.x,  up.x, -Direction.x, 0.0f,
        right.y,  up.y, -Direction.y, 0.0f,
        right.z,  up.z, -Direction.z, 0.0f,
        tx,       ty,   tz,           1.0f 
    };
    Matrix LookAt(4,4,a.data());


    return LookAt;
}

Vision::Camera::Camera(Vec3 startCoords,Vec3 dir, Vec3 up): Position(startCoords),Direction(dir.normalize()), UpVector(up.normalize()){
    yaw = -90;
    pitch = 0;
}


void Vision::Camera::CameraMove(char d){
    if(d == 'w'){
        Position += Direction*cameraSpeed;
    }else if(d == 's'){
        Position -= Direction*cameraSpeed;
    }else if(d == 'd'){
        Position += Cross(Direction,UpVector).normalize()*cameraSpeed;
    }else if(d == 'a'){
        Position -= Cross(Direction,UpVector).normalize()*cameraSpeed;
    }
}



void Vision::Camera::TurnCamera(double dx, double dy){
    yaw += dx;
    pitch += dy;
    if(pitch > 89) pitch = 89.0f;
    if(pitch < -89) pitch = -89.0f;

    double yawRad = yaw*M_PI/180;
    double pitchRad = pitch*M_PI/180;
    

    Direction.x = cos(yawRad)*cos(pitchRad);
    Direction.y = sin(pitchRad);
    Direction.z = sin(yawRad)*cos(pitchRad);
    Direction.normalize();
}