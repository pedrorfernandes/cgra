#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"
#include "myUnitCube.h"
#include "CGFappearance.h"

#define CHAIR_SIT_X 2.75
#define CHAIR_SIT_Y 0.15
#define CHAIR_SIT_Z 2.5

#define CHAIR_BACK_X 2.75
#define CHAIR_BACK_Y 1.25
#define CHAIR_BACK_Z 0.15

#define CHAIR_LEG_X 0.25
#define CHAIR_LEG_Y 2.175
#define CHAIR_LEG_Z 0.25

#define CHAIR_BACK_HOLDER_X 0.25
#define CHAIR_BACK_HOLDER_Y 1.0
#define CHAIR_BACK_HOLDER_Z 0.15

class MyChair: public CGFobject {
private:

	CGFappearance* materialW;
	CGFappearance* materialDM;

	MyUnitCube myCube;

	float angle;
	float magicNumberX;
	float magicNumberZ;

	public:
    MyChair();
		
		void draw();
};


#endif