#ifndef POINT
#define POINT

#include <vector>
#include <math.h>

using namespace std;

class Point {

public:
    Point(float x, float y);
    Point(float x, float y, float z);
float x;
float y;
float z;

};

Point CalculateSurfaceNormal(vector<Point> polygon);

#endif
