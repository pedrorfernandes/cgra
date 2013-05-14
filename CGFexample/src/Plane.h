#pragma once

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#define BORDER_X 0.035
#define BORDER_Z 0.065
#define BORDER_TOP 0.33

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
    void setWindow(bool);
    void drawWindowBorders(double bx, double bz, double tx, double tz);
private:
	double _rows;
    double _columns;
    double _ratio;
    bool _manyTexels;
    bool _isWindow;
};

