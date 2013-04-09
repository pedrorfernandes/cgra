#include "MyClockHand.h"

MyClockHand::MyClockHand(int t): angle(270.0), type(t) {
    float ambBlack[3] = {0, 0, 0};
    float difBlack[3] = {0, 0, 0};
    float specBlack[3] = {0, 0, 0};
    float shininessBlack = 120.f;
    
    float ambRed[3] = {0, 0, 0};
    float difRed[3] = {0, 0, 0};
    float specRed[3] = {0, 0, 0};
    float shininessRed = 120.f;
    
    float ambWhite[3] = {0, 0, 0};
    float difWhite[3] = {0, 0, 0};
    float specWhite[3] = {0, 0, 0};
    float shininessWhite = 120.f;
    
    if (type == HOURS)
        clockHandAppearance = new CGFappearance(ambBlack, difBlack, specBlack, shininessBlack);
    else if (type == MINUTES)
        clockHandAppearance = new CGFappearance(ambRed, difRed, specRed, shininessRed);
    else if (type == SECONDS)
        clockHandAppearance = new CGFappearance(ambWhite, difWhite, specWhite, shininessWhite);

}

void MyClockHand::draw() {
    glPushMatrix();
    glRotatef(180.0-angle, 0.0, 0.0, -1);
    glScaled(0.1, 0.5, 0.1);
    glTranslated(0, 0.5, 0);
    clockHandAppearance->apply();
    cube.draw();
    glPopMatrix();
}