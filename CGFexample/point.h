#ifndef POINT
#define POINT

#include <vector>
#include <math.h>

using namespace std;

class Point {

public:
    Point(double x, double y);
    Point(double x, double y, double z);
double x;
double y;
double z;
    double length();
    Point & operator+(const Point &p);


};

Point calculateSurfaceNormal(vector<Point> polygon);

Point calculateSurfaceNormalTriangle(vector<Point> triangle);

#endif
