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
#include "MyPaperPlane.h"
#include "MyRobot.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0; int light0On;
	CGFlight* light1; int light1On;
	CGFlight* light2; int light2On;
	CGFlight* light3; int light3On;
    CGFlight* light4; int light4On;

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
    MyClockHand* clockHandHours;
    MyClockHand* clockHandMinutes;
    MyClockHand* clockHandSeconds;
    MyPaperPlane* myPaperPlane;
    MyRobot * myBot;
    Plane* landscape;

    CGFappearance* slidesAppearance;
    CGFappearance* boardAppearance;
    CGFappearance* windowAppearance;
    CGFappearance* floorAppearance;
    CGFappearance* wallAppearance;
    CGFappearance* columnAppearance;
    CGFappearance* lampAppearance;
    CGFappearance* robotAppearance;
    CGFappearance* landscapeAppearance;
    
    void toggleSomething();
    
    int clockStop;
        
    void update(unsigned long miliseconds);

	~LightingScene();
};

#endif