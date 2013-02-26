#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"

class ExampleObject: public CGFobject {
	public:
		void draw();
};

class MyUnitCube : public CGFobject {
    public:
        void draw();
};

class MyFloor : public CGFobject {
    public:
        MyUnitCube myCube;
        void draw();
};

class MyTable : public CGFobject {
public:
    void draw();
    MyUnitCube myCube;
};

class MyChair : public CGFobject {
public:
    void draw();
    MyUnitCube myCube;
};


#endif