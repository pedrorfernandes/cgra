#include "point.h"

Point::Point(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

inline float Point::length(){
    return sqrt( (this->x * this->x) + (this->y * this->y) + (this->z * this->z) );
}

Point calculateSurfaceNormal(vector<Point> polygon){
    Point normal(0,0,0);
    for (int i = 0; i < polygon.size(); ++i) {
        Point current = polygon.at(i);
        Point next = polygon.at( (i+1) % polygon.size() );
        
        normal.x = normal.x + ( (current.y - next.y) * (current.z + next.z) );
        normal.y = normal.y + ( (current.z - next.z) * (current.x + next.x) );
        normal.z = normal.z + ( (current.x - next.x) * (current.y + next.y) );
    }
    
    //float length = sqrt( (normal.x * normal.x) + (normal.y * normal.y) + (normal.z * normal.z) );
    float length = normal.length();
    normal.x = normal.x / length;
    normal.y = normal.y / length;
    normal.z = normal.z / length;
    return normal;
}

Point & Point::operator+(const Point &p){
    this->x = (this->x + p.x) / 2;
    this->y = (this->y + p.y) / 2;
    this->z = (this->z + p.z) / 2;
    float length = this->length();
    this->x = (this->x) / length;
    this->y = (this->y) / length;
    this->z = (this->z) / length;
    return *this;
}