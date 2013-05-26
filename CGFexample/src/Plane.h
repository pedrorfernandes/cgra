#pragma once

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#define BORDER_X 0.035
#define BORDER_Z 0.065
#define BORDER_TOP 0.33
#define EPSILON 0.001

#include <math.h>

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
    
    void initializeVertices();
    inline void adjustWindow(double &tx, double &tz);
    
    inline static bool equals(double a, double b);
    
private:
	double _rows;
    double _columns;
    double _ratio;
    bool _manyTexels;
    bool _isWindow;
};

