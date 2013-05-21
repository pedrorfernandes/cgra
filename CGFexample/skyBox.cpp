#include "skyBox.h"

SkyBox::SkyBox(){
    skyFront = new CGFappearance("sky/front.png", GL_CLAMP, GL_CLAMP);
    skyBack = new CGFappearance("sky/back.png", GL_CLAMP, GL_CLAMP);
    skyLeft = new CGFappearance("sky/left.png", GL_CLAMP, GL_CLAMP);
    skyRight = new CGFappearance("sky/right.png", GL_CLAMP, GL_CLAMP);
    skyTop = new CGFappearance("sky/top.png", GL_CLAMP, GL_CLAMP);
    skyBottom = new CGFappearance("sky/bottom.png", GL_CLAMP, GL_CLAMP);
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
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
	//BACK
    skyBack->apply();
	glPushMatrix();
	glRotated(180,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
	//LEFT
    skyLeft->apply();
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
	//RIGHT
    skyRight->apply();
	glPushMatrix();
	glRotated(90,0,1,0);
	glTranslated(0,0,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
	//TOP
    skyTop->apply();
	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1,0,0);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
	//BOTTOM
    skyBottom->apply();
	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1,0,0);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.5f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f, -0.5f, 0.0f);
    glEnd();
	glPopMatrix();
    
    glPopAttrib();
	
}