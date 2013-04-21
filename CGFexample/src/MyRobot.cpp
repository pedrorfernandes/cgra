#include "MyRobot.h"


MyRobot::MyRobot(){
    xTriangle1.push_back(0.5); yTriangle1.push_back(0.3); zTriangle1.push_back(0.0);
    xTriangle1.push_back(-0.5); yTriangle1.push_back(0.3); zTriangle1.push_back(0.0);
    xTriangle1.push_back(0.0); yTriangle1.push_back(0.3); zTriangle1.push_back(2.0);
    
    speed = 0.2;
    x = 0.0;
    y = 0.0;
    z = 0.0;
    angle = 0.0;
    rotationSpeed = 5;
    startingAngle = 90;
    
     pi = acos(-1.0);
     deg2rad=pi/180.0;
}

void MyRobot::draw(){
    glPushMatrix();
    glTranslated( x, y, z );
    glRotated(angle, 0, -1, 0);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < xTriangle1.size(); i++) {
        glNormal3f(xTriangle1.at(i), yTriangle1.at(i), zTriangle1.at(i));
        glVertex3f(xTriangle1.at(i), yTriangle1.at(i), zTriangle1.at(i));
    }
    for (int i = xTriangle1.size()-1; i >= 0; i--) {
        glNormal3f(xTriangle1.at(i), yTriangle1.at(i), zTriangle1.at(i));
        glVertex3f(xTriangle1.at(i), yTriangle1.at(i), zTriangle1.at(i));
    }
    glEnd();
    glPopMatrix();
}

void MyRobot::update(long miliseconds){
    
}