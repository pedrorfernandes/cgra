#ifndef MY_CLOCK_HAND
#define MY_CLOCK_HAND

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "myUnitCube.h"
#include "CGFappearance.h"
#define HOURS 1
#define MINUTES 2
#define SECONDS 3

class MyClockHand : public CGFobject {
    float angle;
    MyUnitCube cube;
    CGFappearance * clockHandAppearance;
    int type;
    double time;
public:
    MyClockHand(int type);
    void draw();
    void setAngle(float);
    void update(long miliseconds);
    void setTime(int hours, int minutes, int seconds);
};

#endif
