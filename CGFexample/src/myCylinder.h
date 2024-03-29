#ifndef MY_CYLINDER
#define MY_CYLINDER

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include <math.h>
#include <vector>

#define PI 3.14159265359

using namespace std;

class MyCylinder : public CGFobject {
    int slices;
    int stacks;
    vector<double> x;
    vector<double> y;
    double zStep;
    bool smooth;
    vector<double> notSmoothX;
    vector<double> notSmoothY;
    bool textureAtBase;
public:
    MyCylinder(int slices, int stacks, bool smooth);
    void draw();
    void drawTextureAtBase();
    void setTextureAtBase(bool);
    
};

#endif
