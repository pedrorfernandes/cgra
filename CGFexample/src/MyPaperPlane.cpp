#include "MyPaperPlane.h"

MyPaperPlane::MyPaperPlane(){

}

void MyPaperPlane::draw() {
    glPushMatrix();
    glScaled(2.0, 0.5, 2.0);
    glPopMatrix();

}