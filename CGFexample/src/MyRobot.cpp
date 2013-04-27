#include "MyRobot.h"


MyRobot::MyRobot(int stacks){

    slices = 12;
    float r = 0.25;
    
    for(double ang = 45.0; ang <= 405.0; ang += (360.0 / slices)) {
        double rad = ang * PI / 180; // degrees to radians
        top.push_back( Point(r * cos(rad), 1.0, r * sin(rad)) );
    }
    float delta = 1.0/3.0;
    deltaSide = stacks+1;
    base.push_back(Point(0.5, 0.01, 0.5)); // top right
    
    // (top) right to left
    base.push_back(Point(0.5-delta, 0.01, 0.5));
    base.push_back(Point(0.5-2*delta, 0.01, 0.5));
    
    base.push_back(Point(-0.5, 0.01, 0.5)); // top left
    
    // (left) top to bottom
    base.push_back(Point(-0.5, 0.01, 0.5-delta));
    base.push_back(Point(-0.5, 0.01, 0.5-2*delta));

    base.push_back(Point(-0.5, 0.01, -0.5)); // bottom left
    
    // (bottom) left to right
    base.push_back(Point(-0.5+delta, 0.01, -0.5));
    base.push_back(Point(-0.5+2*delta, 0.01, -0.5));
    
    base.push_back(Point(0.5, 0.01, -0.5)); // bottom right
    
    // (right) bottom to top
    base.push_back(Point(0.5, 0.01, -0.5+delta));
    base.push_back(Point(0.5, 0.01, -0.5+2*delta));

    
    for(int i = 0; i < base.size(); ++i){
        Point P(base.at(i).x, base.at(i).y, base.at(i).z);
        Point Q(top.at(i).x, top.at(i).y, top.at(i).z);
        Point delta(Q.x - P.x, Q.y - P.y, Q.z - P.z);
        for(float t = 0.0; t < 1.0; t += (1.0/(float)stacks)){
            // line -> P + Q*t
            side.push_back(Point(P.x + delta.x * t,
                                 P.y + delta.y * t,
                                 P.z + delta.z * t));
            
        }
        side.push_back(Q);
    }

    speed = 0.2;
    x = 0.0;
    y = 0.0;
    z = 0.0;
    angle = 0.0;
    rotationSpeed = 5;
    startingAngle = 90;
    
    pi = acos(-1.0);
    deg2rad=pi/180.0;
}

void MyRobot::draw(){
    glPushMatrix();
    glTranslated( x, y, z );
    glRotated(angle, 0, -1, 0);
    
    // the top circle
    glBegin(GL_POLYGON);
    for (int i = top.size()-1; i >= 0; --i) {
        glVertex3d(top.at(i).x, top.at(i).y, top.at(i).z);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    for (int i = 0; i < base.size(); ++i) {
        glNormal3d(base.at(i).x, base.at(i).y, base.at(i).z);
        glVertex3d(base.at(i).x, base.at(i).y, base.at(i).z);
    }
    glEnd();

    int i;
    for(i = 0; i < side.size()-1-deltaSide; i++){
        glBegin(GL_TRIANGLE_STRIP);
        glNormal3d(side.at(i).x, side.at(i).y, side.at(i).z);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
        
        glNormal3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        glVertex3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        
        glNormal3d(side.at(deltaSide+i).x, side.at(deltaSide+i).y, side.at(deltaSide+i).z);
        glVertex3d(side.at(deltaSide+i).x, side.at(deltaSide+i).y, side.at(deltaSide+i).z);
        
        glNormal3d(side.at(deltaSide+i+1).x, side.at(deltaSide+i+1).y, side.at(deltaSide+i+1).z);
        glVertex3d(side.at(deltaSide+i+1).x, side.at(deltaSide+i+1).y, side.at(deltaSide+i+1).z);
        glEnd();
    }
    
    // since we don't repeat vertices, we need to draw the last line connected to the first
    for(int j = 0 ; i < side.size()-1; i++, j++){
        glBegin(GL_TRIANGLE_STRIP);
        glNormal3d(side.at(i).x, side.at(i).y, side.at(i).z);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
        
        glNormal3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        glVertex3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        
        glNormal3d(side.at(j).x, side.at(j).y, side.at(j).z);
        glVertex3d(side.at(j).x, side.at(j).y, side.at(j).z);
        
        glNormal3d(side.at(j+1).x, side.at(j+1).y, side.at(j+1).z);
        glVertex3d(side.at(j+1).x, side.at(j+1).y, side.at(j+1).z);
        glEnd();
    }

    glPopMatrix();
}

void MyRobot::update(long miliseconds){
    
}

void MyRobot::moveForward(){
    x -= speed * cos((startingAngle-angle)*deg2rad);
	z += speed * sin((startingAngle+angle)*deg2rad);
}

void MyRobot::moveBackward(){
    x += speed * cos((startingAngle-angle)*deg2rad);
	z -= speed * sin((startingAngle+angle)*deg2rad);
}

void MyRobot::rotateLeft(){
    angle -= rotationSpeed;
}

void MyRobot::rotateRight(){
    angle += rotationSpeed;
}