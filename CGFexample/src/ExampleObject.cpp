#include "ExampleObject.h"

void ExampleObject::draw() 
{
    glBegin(GL_QUADS);
    glVertex3d(0,0,0);
    glVertex3d(4,0,0);
    glVertex3d(4,3,0);
    glVertex3d(0,3,0);
	glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex3d(-1, 3, 0);
    glVertex3d(5, 3, 0);
    glVertex3d(2, 4, 0);
    glEnd();
}

void MyUnitCube::draw()
{
    // XY front
    glPushMatrix();
    glTranslated(0, 0, 0.5);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();

    // XZ bottom
    glPushMatrix();
    glTranslated(0, -0.5, 0);
    glRotated(90, 1, 0, 0);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();

    // YZ front
    glPushMatrix();
    glTranslated(0.5, 0, 0);
    glRotated(90, 0, 1, 0);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();

    // YZ back
    glPushMatrix();
    glTranslated(-0.5, 0, 0);
    glRotated(-90, 0, 1, 0);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();

    // XY back
    glPushMatrix();
    glTranslated(0, 0, -0.5);
    glRotated(180, 0, 1, 0);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();
    
    // XZ top
    glPushMatrix();
    glTranslated(0, 0.5, 0);
    glRotated(-90, 1, 0, 0);
    glRectd(-0.5,-0.5,0.5,0.5);
    glPopMatrix();
}

void MyFloor::draw(){
    glPushMatrix();
    glScaled(8, 0.1, 6);
    myCube.draw();
    glPopMatrix();
}

void MyTable::draw()
{
    // first leg
    glPushMatrix();
    glTranslated(2.25, 0, 1.25);
    glScaled(0.3, 3.5, 0.3);
    myCube.draw();
    glPopMatrix();
    
    // second leg
    glPushMatrix();
    glTranslated(2.25, 0, -1.25);
    glScaled(0.3, 3.5, 0.3);
    myCube.draw();
    glPopMatrix();
    
    // third leg
    glPushMatrix();
    glTranslated(-2.25, 0, 1.25);
    glScaled(0.3, 3.5, 0.3);
    myCube.draw();
    glPopMatrix();
    
    // fourth leg
    glPushMatrix();
    glTranslated(-2.25, 0, -1.25);
    glScaled(0.3, 3.5, 0.3);
    myCube.draw();
    glPopMatrix();
    
    // top of the table
    glPushMatrix();
    glTranslated(0, 1.75, 0);
    glScaled(5, 0.3, 3);
    myCube.draw();
    glPopMatrix();
    
}

#define CHAIR_LEG_Y 2
#define CHAIR_LEG_X 0.3
#define CHAIR_LEG_Z 0.3

#define CHAIR_LEG_POS_X 1
#define CHAIR_LEG_POS_Z 1


void MyChair::draw(){
    // first leg
    glPushMatrix();
    glTranslated(CHAIR_LEG_POS_X, 0, CHAIR_LEG_POS_Z);
    glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
    myCube.draw();
    glPopMatrix();
    // second leg
    glPushMatrix();
    glTranslated(CHAIR_LEG_POS_X, 0, -CHAIR_LEG_POS_Z);
    glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
    myCube.draw();
    glPopMatrix();
    // third leg
    glPushMatrix();
    glTranslated(-CHAIR_LEG_POS_X, 0, CHAIR_LEG_POS_Z);
    glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
    myCube.draw();
    glPopMatrix();
    // fourth leg
    glPushMatrix();
    glTranslated(-CHAIR_LEG_POS_X, 0, -CHAIR_LEG_POS_Z);
    glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
    myCube.draw();
    glPopMatrix();
    
    // chair top
    glPushMatrix();
    glTranslated(0, CHAIR_LEG_Y/2+0.3/2, 0);
    glScaled(CHAIR_LEG_POS_X*2+CHAIR_LEG_X, 0.3, CHAIR_LEG_POS_Z*2+CHAIR_LEG_Z);
    myCube.draw();
    glPopMatrix();
    
    // chair back
    glPushMatrix();
    glTranslated(0, CHAIR_LEG_Y + 0.3/2 + 0.3 , CHAIR_LEG_POS_Z);
    glScaled(CHAIR_LEG_POS_X*2+CHAIR_LEG_X, CHAIR_LEG_POS_Z*2+CHAIR_LEG_Z, 0.3);
    
    myCube.draw();
    glPopMatrix();
     
    
}