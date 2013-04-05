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
    Plane(int, int);
	~Plane(void);
	void draw();
    void drawWithManyTexels();
    void setRatio(double);
    void setManyTexels(bool);
private:
	double _rows;
    double _columns;
    double _ratio;
    bool _manyTexels;
};

