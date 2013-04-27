#include "MyRobot.h"


MyRobot::MyRobot(int stacks){

    slices = 12;
    double r = 0.25;
    
    for(double ang = 45.0; ang <= 405.0; ang += (360.0 / slices)) {
        double rad = ang * PI / 180; // degrees to radians
        top.push_back( Point(r * cos(rad), 1.0, r * sin(rad)) );
    }
    double delta = 1.0/3.0;
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
        for(double t = 0.0; t <= 1.0; t += (1.0/stacks)){
            // line -> P + (Q-P)*t
            side.push_back(Point(P.x + delta.x * t,
                                 P.y + delta.y * t,
                                 P.z + delta.z * t));
            
        }
    }
    
    for (int i = 0; i < side.size(); ++i) {
        normals.push_back(Point(0,0,0));
    }

    int i;
    for (i = 0; i < side.size()-1-deltaSide; ++i) {
        if ( (i+1) % deltaSide == 0 ) continue;
        vector<Point> triangle1;
        triangle1.push_back( side.at(i) );
        triangle1.push_back( side.at(i+1) );
        triangle1.push_back( side.at(deltaSide+i+1) );
        Point normal1 = calculateSurfaceNormalTriangle(triangle1);
        normals.at(i) + normal1; normals.at(i+1) + normal1; normals.at(deltaSide+i+1) + normal1;
        
        vector<Point> triangle2;
        triangle2.push_back( side.at(i) );
        triangle2.push_back( side.at(deltaSide+i) );
        triangle2.push_back( side.at(deltaSide+i+1) );
        Point normal2 = calculateSurfaceNormalTriangle(triangle2);
        normals.at(i) + normal2; normals.at(deltaSide+i) + normal2; normals.at(deltaSide+i+1) + normal2;
         
    }
    
    // the last line connected to the first
    i++;
    for(int j = 0 ; i < side.size()-1; i++, j++){
        if ( (i+1) % deltaSide == 0 ) continue;
        vector<Point> triangle1; 
        triangle1.push_back( side.at(i) );
        triangle1.push_back( side.at(i+1) );
        triangle1.push_back( side.at(j+1) );
        Point normal1 = calculateSurfaceNormalTriangle(triangle1);
        normals.at(i) + normal1; normals.at(i+1) + normal1; normals.at(j+1) + normal1;
        
        vector<Point> triangle2; 
        triangle2.push_back( side.at(i) );
        triangle2.push_back( side.at(j) );
        triangle2.push_back( side.at(j+1) );
        Point normal2 = calculateSurfaceNormalTriangle(triangle2);
        normals.at(i) + normal2; normals.at(j) + normal2; normals.at(j+1) + normal2;
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
        glNormal3d(0, 1, 0);
        glVertex3d(top.at(i).x, top.at(i).y, top.at(i).z);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    for (int i = 0; i < base.size(); ++i) {
        glNormal3d(0, -1, 0);
        glVertex3d(base.at(i).x, base.at(i).y, base.at(i).z);
    }
    glEnd();
    
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    int i;
    for(i = 0; i < side.size()-1-deltaSide; i++){
        if ( (i+1) % deltaSide == 0 ) continue;
        glBegin(GL_TRIANGLE_STRIP);
        glNormal3d(normals.at(i).x, normals.at(i).y, normals.at(i).z);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
        
        glNormal3d(normals.at(i+1).x, normals.at(i+1).y, normals.at(i+1).z);
        glVertex3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        
        glNormal3d(normals.at(deltaSide+i).x, normals.at(deltaSide+i).y, normals.at(deltaSide+i).z);
        glVertex3d(side.at(deltaSide+i).x, side.at(deltaSide+i).y, side.at(deltaSide+i).z);
        
        glNormal3d(normals.at(deltaSide+i+1).x, normals.at(deltaSide+i+1).y, normals.at(deltaSide+i+1).z);
        glVertex3d(side.at(deltaSide+i+1).x, side.at(deltaSide+i+1).y, side.at(deltaSide+i+1).z);
        glEnd();
    }
    
    // since we don't repeat vertices, we need to draw the last line connected to the first
    i++;
    for(int j = 0 ; i < side.size()-1; i++, j++){
        if ( (i+1) % deltaSide == 0 ) continue;
        glBegin(GL_TRIANGLE_STRIP);
        glNormal3d(normals.at(i).x, normals.at(i).y, normals.at(i).z);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
        
        glNormal3d(normals.at(i+1).x, normals.at(i+1).y, normals.at(i+1).z);
        glVertex3d(side.at(i+1).x, side.at(i+1).y, side.at(i+1).z);
        
        glNormal3d(normals.at(j).x, normals.at(j).y, normals.at(j).z);
        glVertex3d(side.at(j).x, side.at(j).y, side.at(j).z);
        
        glNormal3d(normals.at(j+1).x, normals.at(j+1).y, normals.at(j+1).z);
        glVertex3d(side.at(j+1).x, side.at(j+1).y, side.at(j+1).z);
        glEnd();
    }

    //glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

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