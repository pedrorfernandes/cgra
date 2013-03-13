#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks/*, bool smooth*/): slices(slices), stacks(stacks) {
    
	for(int angle = 0; angle <= 360; angle += (360 / slices)) {
        float rad = angle * PI / 180; // degrees to radians
        x.push_back(cos(rad));
        y.push_back(sin(rad));
    }
    
    zStep = (1.0 / stacks);
}

void myCylinder::draw(){
    
    // Bottom of the cylinder
    // Drawn clockwise
    glBegin(GL_POLYGON);
    for(int i = x.size()-1; i >= 0 ; i--) {
        glNormal3d(0, 0, -1);
        glVertex3f( x.at(i), y.at(i), 0.0);
    }
    glEnd();
    
    // Top (drawn anticlockwise)
    glBegin(GL_POLYGON);
    for(int i = 0; i < x.size() ; i++) {
        glNormal3d(0, 0, 1);
        glVertex3f(x.at(i), y.at(i), 1.0);
    }
    glEnd();
    
    for (float angle = 0; angle < 360; angle += (360.0 / slices) ) {
        glPushMatrix();
        glRotatef(angle, 0.0, 0.0, 1.0);
        for (float z = 0.0; z < 1.0; z += zStep) {
            // rotate and then draw a slice
            glBegin(GL_QUAD_STRIP);
            // draw only 1 slice (4 points in space)
            for(int i = 0; i < 2 ; i++) {
                // point A' (on top)
                glNormal3d(x.at(i), y.at(i), 0.0);
                glVertex3f(x.at(i), y.at(i), z+zStep );
                
                // point A (bottom)
                glNormal3d(x.at(i), y.at(i), 0.0);
                glVertex3f(x.at(i), y.at(i), z);
            }
        }
        glEnd();
        glPopMatrix();
    }    
}
