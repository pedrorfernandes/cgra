#include "MyPaperPlane.h"

MyPaperPlane::MyPaperPlane(vector<float> xVector, vector<float> yVector, vector<float> zVector)
{
    xPoints = xVector;
    yPoints = yVector;
    zPoints = zVector;
    x = xVector.at(0);
    y = yVector.at(0);
    z = zVector.at(0);
    state = TAKEOFF;
    paperPlaneAppearance = NULL;
    angle = 0.0;
    rotationInterval = 0.0;
    distanceInterval = 0.01;
    
    xTriangle1.push_back(0.5); yTriangle1.push_back(0.0); zTriangle1.push_back(-0.5);
    xTriangle1.push_back(0.0); yTriangle1.push_back(0.0); zTriangle1.push_back(0.5);
    xTriangle1.push_back(-0.5); yTriangle1.push_back(0.0); zTriangle1.push_back(-0.5);

    xTriangle2.push_back(0.0); yTriangle2.push_back(-0.3); zTriangle2.push_back(-0.5);
    xTriangle2.push_back(0.0); yTriangle2.push_back(0.0); zTriangle2.push_back(0.5);
    xTriangle2.push_back(0.0); yTriangle2.push_back(0.0); zTriangle2.push_back(-0.5);

}

void MyPaperPlane::draw() {
    glPushMatrix();
        glTranslatef( x, y, z );
        glRotatef(angle, 1, 0, 0);
        glRotatef(90.0, 0, -1, 0);
        glScalef(1.0, 1.0, 1.0);
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
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < xTriangle2.size(); i++) {
            glNormal3f(xTriangle1.at(i), yTriangle1.at(i), zTriangle1.at(i));
            glVertex3f(xTriangle2.at(i), yTriangle2.at(i), zTriangle2.at(i));
        }
        for (int i = xTriangle2.size()-1; i >= 0; i--) {
            glNormal3f(xTriangle2.at(i), yTriangle2.at(i), zTriangle2.at(i));
            glVertex3f(xTriangle2.at(i), yTriangle2.at(i), zTriangle2.at(i));
        }
        glEnd();
    glPopMatrix();

}

void MyPaperPlane::update(long miliseconds){
    switch (state) {
        case TAKEOFF:
            x -= distanceInterval*SPEED;
            if (x <= xPoints.at(1) )
                state = FLYING;
            break;
        case FLYING:
            x -= distanceInterval*SPEED;
            y += distanceInterval*UP_SPEED;
            if (x <= xPoints.at(2) || y >= yPoints.at(2)){
                state = FALLING;
            }
            break;
        case FALLING:
            y -= distanceInterval*SPEED;
            if (rotationInterval == 0.0)
                rotationInterval = 180.0 / ( (yPoints.at(2) - yPoints.at(3) ) / (distanceInterval*SPEED) );
            angle += rotationInterval;
            if (y <= yPoints.at(3))
                state = STOP;
            break;
        default:
            break;
    }
}