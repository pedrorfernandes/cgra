#include "point.h"

Point::Point(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Point CalculateSurfaceNormal(vector<Point> polygon){
    Point normal(0,0,0);
    for (int i = 0; i < polygon.size(); ++i) {
        Point current = polygon.at(i);
        Point next = polygon.at( (i+1) % polygon.size() );
        
        normal.x = normal.x + ( (current.y - next.y) * (current.z + next.z) );
        normal.y = normal.y + ( (current.z - next.z) * (current.x + next.x) );
        normal.z = normal.z + ( (current.x - next.x) * (current.y + next.y) );
    }
    
    float length = sqrt( (normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z) );
    normal.x = normal.x / length;
    normal.y = normal.y / length;
    normal.z = normal.z / length;
    return normal;
}