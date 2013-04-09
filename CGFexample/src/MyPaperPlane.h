#ifndef MY_PAPER_PLANE
#define MY_PAPER_PLANE

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "CGFappearance.h"
#include "myUnitCube.h"

class MyPaperPlane : public CGFobject {
    CGFappearance * clockAppearance;
    MyUnitCube cube;
public:
    MyPaperPlane();
    void draw();
};

#endif
