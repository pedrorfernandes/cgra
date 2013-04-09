#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myChair.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "MyClock.h"
#include "MyClockHand.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
    CGFlight* light4;

	MyTable* table;
	MyChair* chair;
	Plane* wall;
    Plane* window;
    Plane* floor;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
    MyCylinder* cylinderA;
    MyCylinder* cylinderB;
    MyLamp* lamp;
    MyClock* clock;
    MyClockHand* clockHand;
    
    CGFappearance* slidesAppearance;
    CGFappearance* boardAppearance;
    CGFappearance* windowAppearance;
    CGFappearance* floorAppearance;
    CGFappearance* wallAppearance;
    CGFappearance* columnAppearance;
    CGFappearance* lampAppearance;

	~LightingScene();
};

#endif