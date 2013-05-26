#ifndef MY_PAPER_PLANE
#define MY_PAPER_PLANE

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "CGFappearance.h"
#include "myUnitCube.h"
#define TAKEOFF 1
#define FLYING 2
#define FALLING 3
#define STOP 4

#define SPEED 5.0
#define UP_SPEED 0.8

class MyPaperPlane : public CGFobject {
    CGFappearance * paperPlaneAppearance;
    MyUnitCube cube;
    int state;
    vector<float> xPoints;
    vector<float> yPoints;
    vector<float> zPoints;
    float x, y, z;
    double time;
    float angle;
    float rotationInterval;
    float distanceInterval;
    vector<float> xTriangle1;
    vector<float> yTriangle1;
    vector<float> zTriangle1;
    vector<float> xTriangle2;
    vector<float> yTriangle2;
    vector<float> zTriangle2;
public:
    MyPaperPlane(vector<float> x, vector<float> y, vector<float> z);
    void draw();
    void update(long miliseconds);
};

#endif
