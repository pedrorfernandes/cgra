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

class MyRobot{
    vector<float> xTriangle1;
    vector<float> yTriangle1;
    vector<float> zTriangle1;
    double angle;
    double startingAngle;
    double x;
    double y;
    double z;
    double speed;
    double rotationSpeed;
    float pi;
    float deg2rad;

public:
    MyRobot();
    void draw();
    void update(long miliseconds);
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
};


#endif 