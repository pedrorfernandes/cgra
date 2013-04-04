#include "myTable.h"

void myTable::draw() 
{

	glPushMatrix();
	glRotated(angle, 0, 1, 0);
	glTranslated(magicNumberX, 0, magicNumberZ);

	//Table Top
	glPushMatrix();
	glTranslated(0, 3.65, 0);
	glScaled(5, 0.3, 3);
	tableAppearance->apply();
	myCube.draw();
	glPopMatrix();

	//Bottom left leg
	glPushMatrix();
	glTranslated(-2.25, 1.75, 1.25);
	glScaled(0.3, 3.5, 0.3);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Bottom right leg
	glPushMatrix();
	glTranslated(2.25, 1.75, 1.25);
	glScaled(0.3, 3.5, 0.3);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Top left leg
	glPushMatrix();
	glTranslated(-2.25, 1.75, -1.25);
	glScaled(0.3, 3.5, 0.3);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Top right leg
	glPushMatrix();
	glTranslated(2.25, 1.75, -1.25);
	glScaled(0.3, 3.5, 0.3);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	glPopMatrix();
}

void myFloor::draw() {

	//Floor
	glPushMatrix();
	glScaled(50, 0.1, 50);
	myCube.draw();
	glPopMatrix();

}