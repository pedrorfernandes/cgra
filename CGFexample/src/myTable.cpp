#include "myTable.h"

MyTable::MyTable() {
    // Coefficients for Wood
    float ambW[3] = {0.3, 0.1, 0.0};
    float difW[3] = {0.35, 0.15, 0.0};
    float specW[3] = {0.05, 0.05, 0.05};
    float shininessW = 10.f;
    
    // Coefficients for Brass
    float ambMB[3] = {0.229412, 0.123529,0.027451};
    float difMB[3] = {0.680392, 0.468627, 0.013725};
    float specMB[3] = {0.992157, 0.941176, 0.807843};
    float shininessMB = 27.89743616;
    
    // Coefficients for Bronze
    float ambMBr[3] = {0.2125, 0.1275,0.054};
    float difMBr[3] = {0.714, 0.4284, 0.18144};
    float specMBr[3] = {0.393548, 0.271906,0.166721};
    float shininessMBr = 25.6;
    
    // Coefficients for Dark Metal Stuff
    float ambDM[3] = {0.05, 0.05, 0.0};
    float difDM[3] = {0.05, 0.05, 0.0};
    float specDM[3] = {1.0, 1.0, 1.0};
    float shininessDM = 80.f;
    
    // Coefficients for RRuby
    float ambR[3] = {0.1745, 0.01175,0.01175};
    float difR[3] = {0.61424, 0.04136, 0.04136};
    float specR[3] = {0.727811, 0.626959, 0.626959};
    float shininessR = 76.8;
    
    angle = rand() % 41 - 20;
    magicNumberX = rand() % 10 / 10 - 0.5;
    magicNumberZ = rand() % 10 / 10 - 0.5;
    materialW = new CGFappearance(ambW,difW,specW,shininessW);
    materialMB = new CGFappearance(ambMB,difMB,specMB,shininessMB);
    materialMBr = new CGFappearance(ambMBr, difMBr, specMBr, shininessMBr);
    materialDM = new CGFappearance(ambDM, difDM, specDM, shininessDM);
    materialR = new CGFappearance(ambR,difR,specR,shininessR);
    
    tableAppearance = new CGFappearance(ambW,difW,specW, shininessW);
    tableAppearance->setTexture("table.png");
}

void MyTable::draw()
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

void MyFloor::draw() {

	//Floor
	glPushMatrix();
	glScaled(50, 0.1, 50);
	myCube.draw();
	glPopMatrix();

}