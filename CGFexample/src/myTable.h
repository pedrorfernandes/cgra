#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "CGFappearance.h"
#include "myUnitCube.h"

class myTable: public CGFobject {

	CGFappearance* materialW;
	CGFappearance* materialMB;
	CGFappearance* materialMBr;
	CGFappearance* materialDM;
	CGFappearance* materialR;
    CGFappearance* tableAppearance;

	myUnitCube myCube;

	float angle;
	float magicNumberX;
	float magicNumberZ;

	public:
		void draw();

		myTable() {
			angle = rand() % 41 - 20;
			magicNumberX = rand() % 10 / 10 - 0.5;
			magicNumberZ = rand() % 10 / 10 - 0.5;
		}
};

class myFloor: public CGFobject {

	myUnitCube myCube;

	public:
		void draw();
};

#endif