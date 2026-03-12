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
    
    
    Vec3 right = Cross(Direction,UpVector);
    Vec3 up = Cross(Direction,right);
    std::vector<float> a = {right.x, 0, 0, -(Position.x*right.x + Position.y*right.y + Position.z * right.z), 
                            0,       UpVector.y, 0, -(Position.x*UpVector.x + Position.y*UpVector.y + Position.z * UpVector.z), 
                            0, 0                , Direction.z, -(Position.x*Direction.x + Position.y*Direction.y+ Position.z * Direction.z),
                            0, 0, 0 , 1};
    Matrix LookAt(4,4,a.data());


    return LookAt;
}

Vision::Camera::Camera(Vec3 startCoords,Vec3 dir, Vec3 up): Position(startCoords),Direction(dir.normalize()), UpVector(up.normalize()){
    
}


void Vision::Camera::CameraMove(char d){
    if(d == 'w'){
        Position -= Direction*cameraSpeed;
    }else if(d == 's'){
        Position += Direction*cameraSpeed;
    }else if(d == 'd'){
        Position += Cross(Direction,UpVector).normalize()*cameraSpeed;
    }else if(d == 'a'){
        Position -= Cross(Direction,UpVector).normalize()*cameraSpeed;
    }
}