#include "myUnitCube.h"

void myUnitCube::draw() 
{
	//FRONT
	glPushMatrix();
	glTranslated(0,0,0.5);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();

	//BACK
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0.5);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();

	//LEFT
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();

	//FRONT
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0.5);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();

	//TOP
	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1,0,0);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();

	//BOTTOM
	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1,0,0);
	glRectd(0.5, 0.5, -0.5, -0.5);
	glPopMatrix();
	
}