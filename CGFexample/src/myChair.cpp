#include "myChair.h"

MyChair::MyChair(){
    // Coefficients for Wood
	float ambW[3] = {0.3, 0.1, 0.0};
	float difW[3] = {0.35, 0.15, 0.0};
	float specW[3] = {0.05, 0.05, 0.05};
	float shininessW = 10.f;
    
	// Coefficients for Dark Metal Stuff
	float ambDM[3] = {0.05, 0.05, 0.0};
	float difDM[3] = {0.05, 0.05, 0.0};
	float specDM[3] = {1.0, 1.0, 1.0};
	float shininessDM = 80.f;
    
	materialW = new CGFappearance(ambW,difW,specW,shininessW);
    materialW->setTexture("table.png");
	materialDM = new CGFappearance(ambDM, difDM, specDM, shininessDM);
    
    angle = rand() % 41 - 20;
    magicNumberX = rand() % 10 / 10 - 0.5;
    magicNumberZ = rand() % 10 / 10 - 0.5;
}

void MyChair::draw() 
{
	glPushMatrix();

	glRotated(angle, 0, 1, 0);
	glTranslated(magicNumberX / 10, 0, magicNumberZ / 10);

	//Chair Sit
	glPushMatrix();
	glTranslated(0, CHAIR_LEG_Y + CHAIR_SIT_Y/2, 0);
	glScaled(CHAIR_SIT_X, CHAIR_SIT_Y, CHAIR_SIT_Z);
	materialW->apply();
	myCube.draw();
	glPopMatrix();

	//Chair back
	glPushMatrix();
	glTranslated(0, CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y + CHAIR_BACK_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_Z/2));
	glScaled(CHAIR_BACK_X, CHAIR_BACK_Y, CHAIR_BACK_Z);
	materialW->apply();
	myCube.draw();
	glPopMatrix();

	//Chair left back holder
	glPushMatrix();
	glTranslated(-(CHAIR_BACK_X/2 - CHAIR_BACK_HOLDER_X/2), CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_HOLDER_Z/2));
	glScaled(CHAIR_BACK_HOLDER_X, CHAIR_BACK_HOLDER_Y, CHAIR_BACK_HOLDER_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();


	//Chair right back holder
	glPushMatrix();
	glTranslated((CHAIR_BACK_X/2 - CHAIR_BACK_HOLDER_X/2), CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_HOLDER_Z/2));
	glScaled(CHAIR_BACK_HOLDER_X, CHAIR_BACK_HOLDER_Y, CHAIR_BACK_HOLDER_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Bottom left leg
	glPushMatrix();
	glTranslated(-(CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, (CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Bottom right leg
	glPushMatrix();
	glTranslated((CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, (CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Top left leg
	glPushMatrix();
	glTranslated(-(CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	//Top right leg
	glPushMatrix();
	glTranslated((CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	materialDM->apply();
	myCube.draw();
	glPopMatrix();

	glPopMatrix();

	
}