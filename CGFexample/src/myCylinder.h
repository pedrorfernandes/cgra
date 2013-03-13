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

class myCylinder : public CGFobject {
    int slices;
    int stacks;
    vector<float> x;
    vector<float> y;
    float zStep;
public:
    myCylinder(int slices, int stacks/*, bool smooth*/);
    void draw();
    
};



#endif
