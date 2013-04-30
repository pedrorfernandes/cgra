#include "MyRobot.h"


MyRobot::MyRobot(int stacks){

    this->stacks = stacks;
    slices = 12;
    double r = 0.25;
    
    for(double ang = 45.0; ang < 405.0; ang += (360.0 / slices)) {
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
            texels.push_back(Point( ((P.x + delta.x * t)+0.5),
                                   1-((P.z + delta.z * t)+0.5)) );
            
        }
    }
    int multiplier;
    int i; int j; int k;
    vector<Point> polygon;
    Point normal(0,0,0);
    for(multiplier = 0; multiplier < 12; multiplier++){
        i = (multiplier*(stacks + 1)) % (side.size());
        j = (multiplier+11)*(stacks+1) % (side.size());
        k = ((multiplier+1)*(stacks+1)) % (side.size());
        
        // first point normal
        
        Point points[] = {side.at(j), side.at(i+1), side.at(k+1), side.at(k), side.at(i)};
        vector<Point> polygon (points, points + sizeof(points) / sizeof(Point) );
        normal = calculateSurfaceNormal(polygon);
        normals.push_back(normal);
        
        // intermediate points normal
        for(int stack = 1; stack < stacks; stack++){
            i++; j++; k++;
            Point points[] = {side.at(i-1), side.at(j-1), side.at(j), side.at(i+1), side.at(k+1), side.at(k)};
            vector<Point> polygon (points, points + sizeof(points) / sizeof(Point) );
            normal = calculateSurfaceNormal(polygon);
            normals.push_back(normal);
        }
        
        // last point normal
        Point points2[] = {side.at(i), side.at(j), side.at(j+1), side.at(i+1), side.at(k+1)};
        vector<Point> polygon2 (points2, points2 + sizeof(points2) / sizeof(Point) );
        normal = calculateSurfaceNormal(polygon2);
        normals.push_back(normal);

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
    
    // clean the base and top vectors, we don't need them anymore
    base.clear();
    top.clear();
}

void MyRobot::draw(){
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    glPushMatrix();
    glTranslated( x, y, z );
    glRotated(angle, 0, -1, 0);
    
    // the top circle
    glBegin(GL_POLYGON);
    for (int i = side.size()-1; i >= 0; i -= deltaSide) {
        glNormal3d(0, 1, 0);
        glTexCoord2d(texels.at(i).x, texels.at(i).y);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    for (int i = 0; i < side.size(); i += deltaSide) {
        glNormal3d(0, -1, 0);
        glTexCoord2d(texels.at(i).x, texels.at(i).y);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
    }
    glEnd();
    
    int multiplier;
    int i; int j;
    for(multiplier = 1; multiplier < 13; multiplier++){
        i = (multiplier*(stacks + 1)) % (side.size());
        j = (multiplier-1)*(stacks+1);
        glBegin(GL_TRIANGLE_STRIP);

        for(int stack = 0; stack <= stacks; stack++){
            
            glTexCoord2d(texels.at(i).x, texels.at(i).y);
            glNormal3d(normals.at(i).x, normals.at(i).y, normals.at(i).z);
            glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
            i++;
            
            glTexCoord2d(texels.at(j).x, texels.at(j).y);
            glNormal3d(normals.at(j).x, normals.at(j).y, normals.at(j).z);
            glVertex3d(side.at(j).x, side.at(j).y, side.at(j).z);
            j++;
        }
        
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