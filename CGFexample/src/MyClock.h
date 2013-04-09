#ifndef MY_CLOCK
#define MY_CLOCK

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "myCylinder.h"
#define CLOCK_SLICES 12
#define CLOCK_STACKS 1
#include "CGFappearance.h"

class MyClock : public CGFobject {
    MyCylinder cylinder;
    CGFappearance * clockAppearance;
public:
    MyClock();
    void draw();
};

#endif
