#include "myUnitCube.h"

void myUnitCube::draw() 
{
	//FRONT
	glPushMatrix();
	glTranslated(0,0,0.5);
	glNormal3d(0,0,1);
    glBegin(GL_QUADS);
		glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();

	//BACK
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,1);
	glBegin(GL_QUADS);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();

	//LEFT
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,1);
	glBegin(GL_QUADS);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();

	//FRONT
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,1);
	glBegin(GL_QUADS);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();

	//TOP
	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1,0,0);
	glNormal3d(0,0,1);
	glBegin(GL_QUADS);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();

	//BOTTOM
	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1,0,0);
	glNormal3d(0,0,1);
	glBegin(GL_QUADS);
        glTexCoord2d(1.0, 0.0);
        glVertex3d(0.5, -0.5, 0);
		glTexCoord2d(1.0, 1.0);
        glVertex3d(0.5, 0.5, 0);
		glTexCoord2d(0.0, 1.0);
        glVertex3d(-0.5, 0.5, 0);
		glTexCoord2d(0.0, 0.0);
        glVertex3d(-0.5, -0.5, 0);
    glEnd();
	glPopMatrix();
	
}