#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"

#include <math.h>
#include <time.h>

float pi = acos(-1.0);
float deg2rad=pi/180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};
float light4_pos[4] = {0, 4, 7.5, 1.0};

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0.1, 0.1, 0.1, 1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0.8, 0.8};
float shininessA = 120.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

// Coefficients for projection board
float ambPB[3] = {0.2, 0.2, 0.2};
float difPB[3] = {0.6, 0.6, 0.6};
float specPB[3] = {0.1, 0.1, 0.1};
float shininessPB = 10.f;

// Coefficients for board
float ambBD[3] = {0.2, 0.2, 0.2};
float difBD[3] = {0.6, 0.6, 0.6};
float specBD[3] = {0.1, 0.1, 0.1};
float shininessBD = 10.f;

// Coefficients for Wood
float ambW[3] = {0.3, 0.1, 0.0};
float difW[3] = {0.35, 0.15, 0.0};
float specW[3] = {0.05, 0.05, 0.05};
float shininessW = 10.f;

float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};

#define CYLINDER_STACKS 10
#define CYLINDER_SLICES 10
#define CIRCLE_STACKS 5
#define CIRCLE_SLICES 6
#define UPDATE_INTERVAL 16

void LightingScene::init() 
{
	srand((time(NULL)));

	// Enables lighting computations
    //glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
    
	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	//light0->disable();
	//light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	//light1->disable();
	//light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0.0);
	light2->setKl(1.0);
	light2->setKq(0.0);

	//light2->disable();
	//light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(0.0);
	light3->setKl(0.0);
	light3->setKq(1.0);

	//light3->disable();
	//light3->enable();
	   
    light4 = new CGFlight(GL_LIGHT4, light4_pos);
    light4->setAmbient(ambientNull);
    
    //light4->enable();
    //light4->disable();

	// Uncomment below to enable normalization of lighting normal vectors
    glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new MyTable();
	chair = new MyChair();
	wall = new Plane();
    window = new Plane(3, 3);
    floor = new Plane(10, 12);
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
    cylinderA = new MyCylinder(CYLINDER_SLICES, CYLINDER_STACKS, true);
    cylinderB = new MyCylinder(CYLINDER_SLICES, CYLINDER_STACKS, false);
    lamp = new MyLamp(CIRCLE_SLICES, CIRCLE_STACKS);
	
	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);
    
    slidesAppearance = new CGFappearance(ambPB, difPB, specPB, shininessPB);
    slidesAppearance->setTexture("slides.png");
    
    boardAppearance = new CGFappearance(ambBD, difBD, specBD, shininessBD);
    boardAppearance->setTexture("board.png");
    boardB->setRatio(512.0 / 372.0);
    boardAppearance->setTextureWrap(GL_REPEAT, GL_CLAMP_TO_EDGE);
    
    windowAppearance = new CGFappearance("window.png", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);

    floorAppearance = new CGFappearance(ambW, difW, specW, shininessW);
    floorAppearance->setTexture("floor.png");
    floorAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);
    
    wallAppearance = new CGFappearance("wall.png", GL_REPEAT, GL_REPEAT);
    columnAppearance = new CGFappearance("wall.png", GL_REPEAT, GL_REPEAT);
    lampAppearance = new CGFappearance("wall.png", GL_REPEAT, GL_REPEAT);

    window->setManyTexels(true);
    floor->setManyTexels(true);
    
    clock = new MyClock();
    clockHandHours = new MyClockHand(HOURS);
    clockHandHours->setTime(3, 30, 45);
    
    clockHandMinutes = new MyClockHand(MINUTES);
    clockHandMinutes->setTime(3, 30, 45);
    
    clockHandSeconds = new MyClockHand(SECONDS);
    clockHandSeconds->setTime(3, 30, 45);
    
    vector<float> xCoordsPlane, yCoordsPlane, zCoordsPlane;
    xCoordsPlane.push_back(14); yCoordsPlane.push_back(4.2); zCoordsPlane.push_back(8);
    xCoordsPlane.push_back(11); yCoordsPlane.push_back(4); zCoordsPlane.push_back(8);
    xCoordsPlane.push_back(0.5); yCoordsPlane.push_back(5.25); zCoordsPlane.push_back(8);
    xCoordsPlane.push_back(0.5); yCoordsPlane.push_back(0.1); zCoordsPlane.push_back(8);
    
    myPaperPlane = new MyPaperPlane(xCoordsPlane, yCoordsPlane, zCoordsPlane);
    
    setUpdatePeriod(UPDATE_INTERVAL);
}

void LightingScene::update(unsigned long miliseconds){
    clockHandHours->update(UPDATE_INTERVAL);
    clockHandMinutes->update(UPDATE_INTERVAL);
    clockHandSeconds->update(UPDATE_INTERVAL);
    myPaperPlane->update(UPDATE_INTERVAL);
}

void LightingScene::display()
{

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();
    
	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
    //light4->draw();
	
	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section
    
    myPaperPlane->draw();
    
	glPushMatrix();
        glTranslated(7.5, 8.0, 7.5);
        glRotated(90, 1.0, 0.0, 0.0);
        lampAppearance->apply();
        lamp->draw();
    glPopMatrix();
    
    // smooth cylinder
	glPushMatrix();
        glTranslated(2.0, 0.0, 12.0);
        glScaled(1.0, 8.0, 1.0);
        glRotated(-90, 1.0, 0.0, 0.0);
        // smooth
        columnAppearance->apply();
        cylinderA->draw();
	glPopMatrix();
    
    // flat cylinder
    glPushMatrix();
        glTranslated(2.0, 0.0, 2.0);
        glScaled(1.0, 8.0, 1.0);
        glRotated(-90, 1.0, 0.0, 0.0);
        // not smooth
        columnAppearance->apply();
        cylinderB->draw();
	glPopMatrix();
    
    //PlaneWall
	glPushMatrix();
        glTranslated(7.5,4,0);
        glRotated(90.0,1,0,0);
        glScaled(15,0.2,8);
        wallAppearance->apply();
        wall->draw();
	glPopMatrix();
    
	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
        floorAppearance->apply();
		floor->draw();
	glPopMatrix();

	//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
        glRotated(90.0,1,0,0);
		glRotated(-90.0,0,0,1);
        glScaled(15,0.2,8);
        windowAppearance->apply();
		window->draw();
	glPopMatrix();

	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		slidesAppearance->apply();
		boardA->draw();
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		boardAppearance->apply();
		boardB->draw();
	glPopMatrix();
    
    glPushMatrix();
        glTranslated(7.25, 7.5, 0.2);
        glScaled(0.5, 0.5, 0.2);
        glRotated(180.0,1,0,0);
        clockHandHours->draw();
        clockHandMinutes->draw();
        clockHandSeconds->draw();
        clock->draw();
	glPopMatrix();

	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		table->draw();
	glPopMatrix();

	//Dat Chair
	glPushMatrix();
		glTranslated(12, 0, 4);
		chair->draw();
	glPopMatrix();
     
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
    delete(light2);
	delete(light3);
    delete(light4);

	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
    
	delete chair;
    delete window;
    delete floor;
    delete cylinderA;
    delete cylinderB;
    delete lamp;
    
    delete slidesAppearance;
    delete boardAppearance;
    delete windowAppearance;
    delete floorAppearance;
    delete wallAppearance;
    delete columnAppearance;
    delete lampAppearance;
}