#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks, bool smooth):
slices(slices), stacks(stacks), smooth(smooth) {
    
    for(double angle = 0.0; angle <= 360.0; angle += (360.0 / slices)) {
        double rad = angle * PI / 180; // degrees to radians
        x.push_back(cos(rad));
        y.push_back(sin(rad));
    }
    
    zStep = (1.0 / stacks);
    double xn = (x.at(1)+x.at(0)) / 2.0;
    double yn = (y.at(1)+y.at(0)) / 2.0;
    double norm = sqrt(xn*xn + yn*yn);
    normNotSmooth.push_back( xn / norm);
    normNotSmooth.push_back( yn / norm);
}

void myCylinder::draw(){
    
    // Bottom of the cylinder
    // Drawn clockwise
    glBegin(GL_POLYGON);
    for(int i = x.size()-1; i >= 0 ; i--) {
        glNormal3d(0, 0, -1);
        glVertex3d( x.at(i), y.at(i), 0.0);
    }
    glEnd();
    
    // Top (drawn anticlockwise)
    glBegin(GL_POLYGON);
    for(int i = 0; i < x.size() ; i++) {
        glNormal3d(0, 0, 1);
        glVertex3d(x.at(i), y.at(i), 1.0);
    }
    glEnd();
    
    for (double angle = 0.0; angle < 360.0; angle += (360.0 / slices) ) {
        glPushMatrix();
        glRotated(angle, 0.0, 0.0, 1.0);
        for (double z = 0.0; z < (1.0-zStep/2.0); z += zStep) {
            // rotate and then draw a slice
            glBegin(GL_QUADS);
            // draw only 1 slice (4 points in space)
            // point A (bottom)
            if (smooth)
                glNormal3d(x.at(0), y.at(0), 0.0);
            else
                glNormal3d(normNotSmooth.at(0), normNotSmooth.at(1), 0.0);
            glVertex3d(x.at(0), y.at(0), z );
            
            // point B (bottom)
            if (smooth)
                glNormal3d(x.at(1), y.at(1), 0.0);
            else
                glNormal3d(normNotSmooth.at(0), normNotSmooth.at(1), 0.0);
            glVertex3d(x.at(1), y.at(1), z);
            
            // point B' (top)
            if (smooth)
                glNormal3d(x.at(1), y.at(1), 0.0);
            else
                glNormal3d(normNotSmooth.at(0), normNotSmooth.at(1), 0.0);
            glVertex3d(x.at(1), y.at(1), z+zStep );
            
            // point A' (top)
            if (smooth)
                glNormal3d(x.at(0), y.at(0), 0.0);
            else
                glNormal3d(normNotSmooth.at(0), normNotSmooth.at(1), 0.0);
            glVertex3d(x.at(0), y.at(0), z+zStep );

            glEnd();
        }
        glPopMatrix();
    }
}
