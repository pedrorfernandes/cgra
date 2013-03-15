#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/) {
	this->slices = slices;
	this->stacks = stacks;
	
	/* This here calculates all the vertices for the base of the "cylinder", depending on the number of slices.
	   It uses three vectors, one for the x coordinates of the points, one for the y coordinates, and another one for the z coordinates.
	   We calculate the vertice coordinates by finding out the angle at which they will be located. A circle has 360 degrees, if we want
	   n slices, we have that each vertice will be at 360/n degrees from eachother. For example, with 4 slices, each vertice will be at
	   360/4 = 90º from each other. Using cos and sin functions we can find out the x and y points, respectively.
	 */
	for(int i = 0; i < 360; i += (360 / slices)) {

		/* a is the angle. We have to use radians with these functions, this converts i to radians */
		float a = i * PI / 180;

		/* pushes to the vector the x coordinate respective to the "a" angle */
		xPoints.push_back(cos(a));

		/* pushes to the vector the y coordinate respective to the "a" angle */
		yPoints.push_back(sin(a));

		/* pushes to the vector the z coordinate. We want z = 0, for now */
		zPoints.push_back(0.0);

		/* this pushes the "module" of the vector given by the point calculated earlier. It's useful for normal vector calculation */
		norms.push_back(norm(cos(a), sin(a), 0.0));
	}
}

float myCylinder::norm(float x, float y, float z) {
	return sqrt(x*x + y*y + z*z);
}

void myCylinder::draw() {
	float h = 1.0 / stacks;

	//Cylinder Base
	glBegin(GL_POLYGON);
		for(int i = xPoints.size() - 1; i >= 0; i--) {
			glNormal3f(xPoints[i]/norms[i], yPoints[i]/norms[i], zPoints[i]/norms[i]);
			glVertex3f(xPoints[i], yPoints[i], zPoints[i]);
		}
	glEnd();

	//Cylinder Top
	glBegin(GL_POLYGON);
		for(int i = 0; i < xPoints.size(); i++) {
			glNormal3f(xPoints[i]/norms[i], yPoints[i]/norms[i], zPoints[i]/norms[i]);
			glVertex3f(xPoints[i], yPoints[i], zPoints[i] + 1);
		}
	glEnd();

	//Cylinder Stripe
	for(float j = 1; j <= stacks; j++) {
		for(int i = 0; i < slices; i++) {
			glBegin(GL_POLYGON);
				if(i < slices-1) {
					glNormal3f(xPoints[i]/norms[i], yPoints[i]/norms[i], zPoints[i]/norms[i]);
					glVertex3f(xPoints[i], yPoints[i], zPoints[i]);

					glNormal3f(xPoints[i+1]/norms[i+1], yPoints[i+1]/norms[i+1], zPoints[i]/norms[i+1]);
					glVertex3f(xPoints[i+1], yPoints[i+1], zPoints[i+1]);

					glNormal3f(xPoints[i+1]/norms[i+1], yPoints[i+1]/norms[i+1], (zPoints[i+1]+ j*h)/norms[i+1]);
					glVertex3f(xPoints[i+1], yPoints[i+1], zPoints[i+1] + j*h);

					glNormal3f(xPoints[i]/norms[i+1], yPoints[i]/norms[i+1], (zPoints[i] + j*h)/norms[i+1]);
					glVertex3f(xPoints[i], yPoints[i], zPoints[i] + j*h);
				}
				else {
					float n = norm(xPoints[i], yPoints[i], zPoints[i]);
					glNormal3f(xPoints[i]/n, yPoints[i]/n, zPoints[i]/n);
					glVertex3f(xPoints[i], yPoints[i], zPoints[i]);
					n = norm(xPoints[0], yPoints[0], zPoints[0]);
					glNormal3f(xPoints[0]/n, yPoints[0]/n, zPoints[0]/n);
					glVertex3f(xPoints[0], yPoints[0], zPoints[0]);
					n = norm(xPoints[0], yPoints[0], zPoints[0] + j*h);
					glNormal3f(xPoints[0]/n, yPoints[0]/n, (zPoints[0] + j*h)/n);
					glVertex3f(xPoints[0], yPoints[0], zPoints[0] + j*h);
					n = norm(xPoints[i], yPoints[i], zPoints[i] + j*h);
					glNormal3f(xPoints[i]/n, yPoints[i]/n, (zPoints[i] + j*h)/n);
					glVertex3f(xPoints[i], yPoints[i], zPoints[i] + j*h);
				}
			glEnd();
		}
	}
		

}