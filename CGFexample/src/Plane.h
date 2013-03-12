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
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

