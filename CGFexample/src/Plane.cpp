#include "Plane.h"
#include "myUnitCube.h"
#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/GLU.h>
#endif

Plane::Plane(void)
{
	_numDivisions = 1;
    _ratio = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
    _ratio = 1;
}

void Plane::setRatio(double ratio)
{
    _ratio = ratio;
}

Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef( 1.0 / _numDivisions, 1 , 1.0 / _numDivisions);
		glNormal3f(0,-1,0);

		for (double bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
                glTexCoord2d(bx / _numDivisions, 0);
				glVertex3f(bx, 0, 0);
				for (double bz = 0; bz < _numDivisions; bz++)
				{
                    glTexCoord2d( (bx+1) / _numDivisions, (bz / _numDivisions) * _ratio);
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2d( bx / _numDivisions, ((bz+1) / _numDivisions) * _ratio);
                    glVertex3f(bx, 0, bz + 1);
				}
                glTexCoord2d( (bx+1) / _numDivisions, 1 * _ratio);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}
