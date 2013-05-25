#include "Plane.h"
#include "myUnitCube.h"
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/GLU.h>
#endif

Plane::Plane(void)
{
	_rows = 1;
    _columns = 1;
    _ratio = 1;
    _manyTexels = false;
    _isWindow = false;
}

Plane::Plane(int n)
{
	_rows = n;
    _columns = n;
    _ratio = 1;
    _manyTexels = false;
    _isWindow = false;
}

Plane::Plane(int rows, int columns)
{
	_rows = rows;
    _columns = columns;
    _ratio = 1;
    _manyTexels = false;
    _isWindow = false;
}

void Plane::setRatio(double ratio)
{
    _ratio = ratio;
}

Plane::~Plane(void)
{
}

void Plane::setManyTexels(bool hasManyTexels){
    this->_manyTexels = hasManyTexels;
}

void Plane::draw()
{
    if (_manyTexels) { drawWithManyTexels(); return; }
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef( 1.0 / _rows, 1 , 1.0 / _columns);
		glNormal3f(0,-1,0);

		for (double bx = 0; bx<_rows; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
                glTexCoord2d(bx / _rows, 0);
				glVertex3f(bx, 0, 0);
				for (double bz = 0; bz < _columns; bz++)
				{
                    glTexCoord2d( (bx+1) / _rows, (bz / _columns) * _ratio);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2d( bx / _rows, ((bz+1) / _columns) * _ratio);
                    glVertex3f(bx, 0, bz + 1);
				}
                glTexCoord2d( (bx+1) / _rows, 1 * _ratio);
				glVertex3d(bx+ 1, 0, _columns);

			glEnd();
		}
	glPopMatrix();

}

void Plane::setWindow(bool isWindow){
    _isWindow = isWindow;
}

bool Plane::equals(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

void Plane::drawWithManyTexels()
{    
	glPushMatrix();
    glRotatef(180.0,1,0,0);
    glTranslatef(-0.5,0.0,-0.5);
    glScalef( 1.0 / _rows, 1 , 1.0 / _columns);
    glNormal3f(0,-1,0);
    
    double tx = -2;
    double tz;

    for (double bx = 0; bx < _rows; bx++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        tx++; tz = -1;
        if (_isWindow) adjustWindow(tx, tz);
        
        glTexCoord2d(tx , tz);
        glVertex3f(bx, 0, 0);
        for (double bz = 0; bz < _columns; bz++)
        {
            tx += 1; if (_isWindow) adjustWindow(tx, tz);
            glTexCoord2d( (tx) , (tz ) * _ratio);
            glVertex3f(bx + 1, 0, bz);
            tx -= 1; if (_isWindow) adjustWindow(tx, tz);
            
            if (_isWindow && (bx == 1 && bz == 1) ){
                // skip the middle of the wall
                glEnd();
                glBegin(GL_TRIANGLE_STRIP);
            }
            
            tz += 1; if (_isWindow) adjustWindow(tx, tz);
            glTexCoord2d( tx , (tz) * _ratio);
            glVertex3f(bx, 0, bz + 1);
            tz -= 1; if (_isWindow) adjustWindow(tx, tz);
            
            tz++;
        }
        
        tx += 1; if (_isWindow) adjustWindow(tx, tz);
        glTexCoord2d( (tx) , _columns-1 * _ratio);
        glVertex3d(bx+ 1, 0, _columns);
        tx -= 1; if (_isWindow) adjustWindow(tx, tz);
        
        glEnd();
    }
    
	glPopMatrix();
    
}

inline void Plane::adjustWindow(double &tx, double &tz){
    if ( equals(tx, -1.0+BORDER_X) ){
        tx -= BORDER_X;
    }
    if ( equals(tx, 0.0) ){
        tx += BORDER_X;
    }
    if ( equals(tx, 1.0+BORDER_X) ){
        tx -= 2*BORDER_X;
    }
    if ( equals(tx, 0.0-BORDER_X) ){
        tx += 2*BORDER_X;
    }
    
    
    if ( equals(tz, 0.0) ){
        tz += BORDER_Z;
    }
    if ( equals(tz, 1.0+BORDER_Z) ){
        tz -= BORDER_Z;
        tz -= BORDER_TOP;
    }
    if ( equals(tz, 2.0-BORDER_TOP) ){
        tz += BORDER_TOP;
    }
}

void Plane::drawWindowBorders(double bx, double bz, double tx, double tz){
    // left border
    glBegin(GL_QUADS);
    glTexCoord2d( (tx) , (tz) * _ratio);
    glVertex3d(bx, 0, bz);
    
    glTexCoord2d( (tx+BORDER_X) , (tz) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz);
    
    glTexCoord2d( (tx+BORDER_X) , (tz+1) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz+1);
    
    glTexCoord2d( (tx) , (tz+1) * _ratio);
    glVertex3d(bx, 0, bz+1);
    glEnd();
    
    // right border
    glBegin(GL_QUADS);
    glTexCoord2d( (tx+1-BORDER_X) , (tz) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz);
    
    glTexCoord2d( (tx+1) , (tz) * _ratio);
    glVertex3d(bx+1, 0, bz);
    
    glTexCoord2d( (tx+1) , (tz+1) * _ratio);
    glVertex3d(bx+1, 0, bz+1);
    
    glTexCoord2d( (tx+1-BORDER_X) , (tz+1) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz+1);
    glEnd();
    
    // down border
    glBegin(GL_QUADS);
    glTexCoord2d( (tx+BORDER_X) , (tz) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz);
    
    glTexCoord2d( (tx+1-BORDER_X) , (tz) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz);
    
    glTexCoord2d( (tx+1-BORDER_X) , (tz+BORDER_Z) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz+BORDER_Z);
    
    glTexCoord2d( (tx+BORDER_X) , (tz+BORDER_Z) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz+BORDER_Z);
    glEnd();
    
    // up border
    glBegin(GL_QUADS);
    glTexCoord2d( (tx+BORDER_X) , (tz+1-BORDER_TOP) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz+1-BORDER_TOP);
    
    glTexCoord2d( (tx+1-BORDER_X) , (tz+1-BORDER_TOP) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz+1-BORDER_TOP);
    
    glTexCoord2d( (tx+1-BORDER_X) , (tz+1) * _ratio);
    glVertex3d(bx+1-BORDER_X, 0, bz+1);
    
    glTexCoord2d( (tx+BORDER_X) , (tz+1) * _ratio);
    glVertex3d(bx+BORDER_X, 0, bz+1);
    glEnd();
}

