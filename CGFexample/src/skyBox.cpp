#include "skyBox.h"

SkyBox::SkyBox(){
    skyFront = new CGFappearance("front.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    skyBack = new CGFappearance("back.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    skyLeft = new CGFappearance("left.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    skyRight = new CGFappearance("right.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    skyTop = new CGFappearance("top.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
    skyBottom = new CGFappearance("bottom.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
}

void SkyBox::draw()
{
    glPushAttrib(GL_ENABLE_BIT);
    //glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
    
	//FRONT
    skyFront->apply();
	glPushMatrix();
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
	//BACK
    skyBack->apply();
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
	//LEFT
    skyLeft->apply();
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
	//RIGHT
    skyRight->apply();
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
	//TOP
    skyTop->apply();
	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1,0,0);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
	//BOTTOM
    skyBottom->apply();
	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1,0,0);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
    glPopAttrib();
	
}