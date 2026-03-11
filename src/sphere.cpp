#include "shapes/sphere.h"
#include "math.h"
using namespace shapes;


void Sphere::CreateMatrix(){
    double phi = (M_PI/accuracy);
    double dzeta = 2*M_PI/accuracy;
    
    unsigned long K = 1 + accuracy*accuracy;
    coords = new Matrix(K,3);
    double x =0;
    double y =0;
    double z =0;
    (*coords)[0] = startCoords.x;
    (*coords)[1] = startCoords.y;
    (*coords)[2] = startCoords.z;
    int k = 3;
    for(int i = 0; i < accuracy; i++){
        z = r*sin(dzeta*i);
        for(int j = 0; j < accuracy; j++){
            x = r*cos(dzeta*i)*cos(phi*j);
            y = r*cos(dzeta*i)*sin(phi*j);
            (*coords)[k] = startCoords.x + x;
            (*coords)[k+1] = startCoords.y + y;
            (*coords)[k+2] = startCoords.z + z;
            k+=3;
        }
        
        
    }
}

void Sphere::draw(){
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS,0,accuracy*accuracy+1);
    glBindVertexArray(0);
}
Sphere::Sphere(const Vec3& startCoords,unsigned int acc, double r) : Shape(startCoords), accuracy(acc), r(r){
    CreateMatrix();
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, coords->getSize() * sizeof(double), coords->getData(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

}

Sphere::~Sphere(){

}