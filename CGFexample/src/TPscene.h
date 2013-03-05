#ifndef TPSCENE_H
#define TPSCENE_H

#include <time.h>
#include "CGFscene.h"
#include "ExampleObject.h"
#include "myUnitCube.h"
#include "myTable.h"
#include "myChair.h"


class TPscene : public CGFscene
{
public:
	//ExampleObject myObject;
	//myUnitCube myCube;
	myTable table;
	myFloor floor;
	myChair chair;

	vector<myChair> chairs;
	vector<myTable> tables;

	void init();
	void display();


};

#endif