#ifndef MY_ROBOT
#define MY_ROBOT

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "CGFappearance.h"
#include "myUnitCube.h"

class MyRobot{
    vector<float> xTriangle1;
    vector<float> yTriangle1;
    vector<float> zTriangle1;

public:
    MyRobot();
    void draw();
    void update(long miliseconds);
};


#endif 