#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "CGFappearance.h"
#include "myUnitCube.h"

class MyTable: public CGFobject {
    
	CGFappearance* materialW;
	CGFappearance* materialMB;
	CGFappearance* materialMBr;
	CGFappearance* materialDM;
	CGFappearance* materialR;
    CGFappearance* tableAppearance;

	MyUnitCube myCube;

	float angle;
	float magicNumberX;
	float magicNumberZ;

	public:
    void draw();
    MyTable();
};

class MyFloor: public CGFobject {

	MyUnitCube myCube;

	public:
		void draw();
    
};

#endif