#include "MyRobot.h"

MyRobot::MyRobot(){
    xTriangle1.push_back(0.5); yTriangle1.push_back(0.3); zTriangle1.push_back(0.0);
    xTriangle1.push_back(-0.5); yTriangle1.push_back(0.3); zTriangle1.push_back(0.0);
    xTriangle1.push_back(0.0); yTriangle1.push_back(0.3); zTriangle1.push_back(2.0);
}

void MyRobot::draw(){
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

}

void MyRobot::update(long miliseconds){
    
}