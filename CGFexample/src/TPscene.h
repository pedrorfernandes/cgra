#ifndef TPSCENE_H
#define TPSCENE_H

#include "CGFscene.h"
#include "ExampleObject.h"

class TPscene : public CGFscene
{
public:
	void init();
	void display();
    ExampleObject myObject;
    //MyUnitCube myUnitCube;
    MyTable myTable;
    MyFloor myFloor;
};

#endif