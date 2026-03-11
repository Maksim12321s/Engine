#include "shapes/shape.h"


Shape::Shape():Shape(Vec3(0,0,0)){

}

Shape::Shape(const Vec3& startCoords) : startCoords(startCoords){

}


Matrix& Shape::GetMatrixCoords(){
    return *coords;
}

Vec3 Shape::GetStartCoords() const{
    return startCoords;
}

Shape::~Shape(){
    if(coords != nullptr){
        delete coords;
    }
}