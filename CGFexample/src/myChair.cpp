#include "myChair.h"

void myChair::draw() 
{
	glPushMatrix();

	glRotated(angle, 0, 1, 0);
	glTranslated(magicNumberX / 10, 0, magicNumberZ / 10);

	//Chair Sit
	glPushMatrix();
	glTranslated(0, CHAIR_LEG_Y + CHAIR_SIT_Y/2, 0);
	glScaled(CHAIR_SIT_X, CHAIR_SIT_Y, CHAIR_SIT_Z);
	myCube.draw();
	glPopMatrix();

	//Chair back
	glPushMatrix();
	glTranslated(0, CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y + CHAIR_BACK_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_Z/2));
	glScaled(CHAIR_BACK_X, CHAIR_BACK_Y, CHAIR_BACK_Z);
	myCube.draw();
	glPopMatrix();

	//Chair left back holder
	glPushMatrix();
	glTranslated(-(CHAIR_BACK_X/2 - CHAIR_BACK_HOLDER_X/2), CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_HOLDER_Z/2));
	glScaled(CHAIR_BACK_HOLDER_X, CHAIR_BACK_HOLDER_Y, CHAIR_BACK_HOLDER_Z);
	myCube.draw();
	glPopMatrix();


	//Chair right back holder
	glPushMatrix();
	glTranslated((CHAIR_BACK_X/2 - CHAIR_BACK_HOLDER_X/2), CHAIR_LEG_Y + CHAIR_SIT_Y + CHAIR_BACK_HOLDER_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_BACK_HOLDER_Z/2));
	glScaled(CHAIR_BACK_HOLDER_X, CHAIR_BACK_HOLDER_Y, CHAIR_BACK_HOLDER_Z);
	myCube.draw();
	glPopMatrix();

	//Bottom left leg
	glPushMatrix();
	glTranslated(-(CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, (CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	myCube.draw();
	glPopMatrix();

	//Bottom right leg
	glPushMatrix();
	glTranslated((CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, (CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	myCube.draw();
	glPopMatrix();

	//Top left leg
	glPushMatrix();
	glTranslated(-(CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	myCube.draw();
	glPopMatrix();

	//Top right leg
	glPushMatrix();
	glTranslated((CHAIR_SIT_X/2 - CHAIR_LEG_X/2), CHAIR_LEG_Y/2, -(CHAIR_SIT_Z/2 - CHAIR_LEG_Z/2));
	glScaled(CHAIR_LEG_X, CHAIR_LEG_Y, CHAIR_LEG_Z);
	myCube.draw();
	glPopMatrix();

	glPopMatrix();

	
}