#pragma once

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
    void setRatio(double);
private:
	double _numDivisions; // Number of triangles that constitute rows/columns
    double _ratio;
};

