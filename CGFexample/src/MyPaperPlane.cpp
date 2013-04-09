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
}

void MyPaperPlane::draw() {
    glPushMatrix();
    glTranslatef( x, y, z );
    glRotatef(angle, 1, 0, 0);
    glScalef(1.0, 0.2, 0.7);
    cube.draw();
    glPopMatrix();

}

void MyPaperPlane::update(long miliseconds){
    switch (state) {
        case TAKEOFF:
            x -= 0.05*SPEED;
            if (x <= xPoints.at(1) )
                state = FLYING;
            break;
        case FLYING:
            x -= 0.05*SPEED;
            y += 0.01;
            if (x <= xPoints.at(2) || y >= yPoints.at(2))
                state = FALLING;
            break;
        case FALLING:
            y -= 0.05*SPEED;
            angle += 9;
            if (y <= yPoints.at(3))
                state = STOP;
            break;
        default:
            break;
    }
}