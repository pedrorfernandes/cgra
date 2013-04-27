#ifndef MY_ROBOT
#define MY_ROBOT

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "CGFappearance.h"
#include "myUnitCube.h"
#include <math.h>

#define PI 3.14159265359

#include "myLamp.h"
#include "myCylinder.h"
#include "point.h"

#include <iostream>

class MyRobot{
    double angle;
    double startingAngle;
    double x;
    double y;
    double z;
    double speed;
    double rotationSpeed;
    double pi;
    double deg2rad;
    
    int deltaSide;
    int slices;
    vector<Point> base;
    vector<Point> top;
    vector<Point> side;
    vector<Point> normals;
    

public:
    MyRobot(int stacks);
    void draw();
    void update(long miliseconds);
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
};


#endif 